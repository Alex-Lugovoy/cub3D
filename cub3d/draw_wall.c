/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsophia <bsophia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:09:56 by bsophia           #+#    #+#             */
/*   Updated: 2021/03/24 18:50:37 by bsophia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			color_put(t_data *img)
{
	char	*dest;

	dest = img->images[img->texture]->addr + ((int)img->tex_y *
		img->images[img->texture]->line_length +
		(int)img->tex_x * (img->images[img->texture]->bits_per_pixel / 8));
	img->color = *(unsigned int*)dest;
	return (img->color);
}

int			color_put_sp(t_data *img, int x, int y)
{
	char	*dest;

	dest = img->sprite[0]->addr + ((int)y * img->sprite[0]->line_length +
		(int)x * (img->sprite[0]->bpp / 8));
	img->color = *(unsigned int*)dest;
	return (img->color);
}

void		draw_wall(t_data *img)
{
	int		start;
	int		end;
	int		first;
	double	koef;

	start = img->wind_height / 2 - (img->wind_height / img->save_luch *
		CUBIK) / 2;
	end = img->wind_height / 2 + (img->wind_height / img->save_luch *
		CUBIK) / 2;
	first = start;
	koef = (double)img->images[img->texture]->images_height / (end - start);
	if (start < 0)
		start = 0;
	while (end > start && start < img->wind_height && img->x_for_wall <
		img->wind_width && end >= 0 && img->x_for_wall >= 0 &&
		img->tex_x < img->images[img->texture]->images_width &&
		img->tex_y < img->images[img->texture]->images_height)
	{
		img->tex_y = (int)((start - first) * koef);
		img->color = color_put(img);
		my_mlx_pixel_put(img, img->x_for_wall, start, img->color);
		start++;
	}
}

void		draw_ceiling(t_data *img)
{
	while (img->count < img->wind_height / 2)
	{
		my_mlx_pixel_put(img, img->x_for_wall, img->count, img->color_ceil);
		img->count++;
	}
	while (img->count < img->wind_height)
	{
		my_mlx_pixel_put(img, img->x_for_wall, img->count, img->color_floor);
		img->count++;
	}
}

void		print_slice(t_data *img)
{
	int		cross;

	cross = 0;
	img->texture = 0;
	img->count = 0;
	if (img->goriz_distant > img->vert_distant)
		vert_dist(img, &cross);
	else
		goriz_dist(img, &cross);
	if (img->angle > 0 && img->angle < M_PI && cross == 2)
		img->texture = 1;
	else if (img->angle > M_PI && img->angle < M_PI * 2 && cross == 2)
		img->texture = 2;
	else if (img->angle > M_PI / 2 && img->angle < 3 * M_PI / 2 && cross == 1)
		img->texture = 3;
	draw_ceiling(img);
	draw_wall(img);
}
