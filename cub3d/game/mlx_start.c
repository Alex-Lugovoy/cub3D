/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsophia <bsophia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:55:44 by bsophia           #+#    #+#             */
/*   Updated: 2021/03/22 16:07:51 by bsophia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		mlx_start(t_data *img)
{
	img->mlx_win = mlx_new_window(img->mlx, img->wind_width, img->wind_height,
		"Cub3D");
	img->img = mlx_new_image(img->mlx, img->wind_width, img->wind_height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
		&img->line_length, &img->endian);
	if (!(img->dist_luch = (double*)malloc(sizeof(double) * img->wind_width)))
		return (-1);
	return (0);
}
