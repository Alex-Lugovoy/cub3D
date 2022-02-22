/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsophia <bsophia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 15:02:31 by bsophia           #+#    #+#             */
/*   Updated: 2021/03/24 20:32:52 by bsophia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		fix_direcrion(t_data *img)
{
	while (img->sprite[img->num_sp]->sprite_dir - img->direction > M_PI)
		img->sprite[img->num_sp]->sprite_dir -= 2 * M_PI;
	while (img->sprite[img->num_sp]->sprite_dir - img->direction < -M_PI)
		img->sprite[img->num_sp]->sprite_dir += 2 * M_PI;
}

static void		calculator_for_sprite(t_data *img)
{
	img->sprite[img->num_sp]->sprite_dir = atan2(img->y_gamer -
		img->sprite[img->num_sp]->y, img->sprite[img->num_sp]->x -
		img->x_gamer);
	fix_direcrion(img);
	img->sprite[img->num_sp]->sprite_size = (double)img->wind_height /
		img->sprite[img->num_sp]->distanse * 32;
	img->s_first_vertical = (img->direction -
		img->sprite[img->num_sp]->sprite_dir) / (M_PI / 3) *
		(double)img->wind_width + (double)(img->wind_width / 2) -
		(img->sprite[img->num_sp]->sprite_size / 2.0);
	img->s_first_goriz = img->wind_height / 2 -
		img->sprite[img->num_sp]->sprite_size / 2;
	img->s_step_xx = (img->sprite[0]->width /
		img->sprite[img->num_sp]->sprite_size);
	img->s_step_yy = (img->sprite[0]->height /
		img->sprite[img->num_sp]->sprite_size);
	img->s_text_x = 0;
	img->s_text_y = 0;
	img->s_x = -1;
	img->s_y = -1;
	img->s_b = 0;
	img->s_bb = 0;
}

static void		text_yy(t_data *img)
{
	img->s_y = -1;
	img->s_text_y = 0;
}

static int		check_if(t_data *img)
{
	if ((int)(img->s_x + img->s_first_vertical) < img->wind_width &&
			(int)(img->s_x + img->s_first_vertical) >= 0 &&
			img->sprite[img->num_sp]->distanse > 30)
		return (1);
	return (0);
}

void			draw_sprite(t_data *img)
{
	calculator_for_sprite(img);
	while (++img->s_x < img->sprite[img->num_sp]->sprite_size)
	{
		if (img->s_x + img->s_first_vertical > img->wind_width)
			break ;
		if (check_if(img))
		{
			text_yy(img);
			while (++img->s_y < img->sprite[img->num_sp]->sprite_size &&
				img->s_text_x < img->sprite[0]->width)
			{
				img->color = color_put_sp(img, (int)img->s_text_x,
					(int)img->s_text_y);
				img->s_b = (int)(img->s_x + img->s_first_vertical);
				img->s_bb = (int)(img->s_y + img->s_first_goriz);
				if (img->color != 0 && img->sprite[img->num_sp]->distanse
					< img->dist_luch[img->s_b] && img->s_b < img->wind_width
					&& img->s_bb < img->wind_height && img->s_b >= 0 &&
					img->s_bb >= 0 && img->sprite[img->num_sp]->distanse > 30)
					my_mlx_pixel_put(img, img->s_b, img->s_bb, img->color);
				img->s_text_y += img->s_step_yy;
			}
		}
		img->s_text_x += img->s_step_xx;
	}
}
