/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsophia <bsophia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 11:02:28 by bsophia           #+#    #+#             */
/*   Updated: 2021/03/24 19:24:26 by bsophia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x *
		(data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void		cast_ray_final2(t_data *img)
{
	int		i;

	img->angle = img->direction + M_PI / 6;
	i = 0;
	img->x_for_wall = 0;
	while (i < img->wind_width)
	{
		if (img->angle > 2 * M_PI)
			img->angle = img->angle - (2 * M_PI);
		if (img->angle < 0)
			img->angle = img->angle + (2 * M_PI);
		first_hit_gorizont_wall(img);
		first_hit_vertical_wall(img);
		search_wall_gorizont(img);
		search_wall_vertical(img);
		serch_distanse_to_the_wall(img);
		print_slice(img);
		i++;
		img->angle -= (M_PI / 3.0) / (double)img->wind_width;
		img->x_for_wall++;
	}
	i_love_sprite(img);
}

int			close123(t_data *img)
{
	mlx_destroy_window(img->mlx, img->mlx_win);
	free_content(img);
	return (0);
}

int			main(int argc, char **argv)
{
	t_data	*img;

	img = malloc(sizeof(t_data));
	img->mlx = mlx_init();
	if (argc < 2 || argc > 3)
		return (0);
	if (-1 == check_first_argument(argv[1]))
		free_content(img);
	if (-1 == read_file(img, argv[1]))
	{
		printf("Error\n");
		free_content(img);
		return (0);
	}
	if (-1 == mlx_start(img))
		close123(img);
	press_butt(12, img);
	if (argc == 3)
	{
		check_two_arguments(img, argv[2]);
		close123(img);
	}
	loop_hook(img);
	return (0);
}
