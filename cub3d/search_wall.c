/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsophia <bsophia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 19:25:43 by bsophia           #+#    #+#             */
/*   Updated: 2021/03/22 15:51:34 by bsophia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		search_wall_gorizont(t_data *img)
{
	int		x;
	int		y;

	x = (int)img->x_gor_dot / CUBIK;
	y = (int)img->y_gor_dot / CUBIK;
	while (y < img->count_line && y > -1 && x > -1 && x < img->map2[y])
	{
		if (img->map[y][x] != '1')
		{
			img->x_gor_dot = img->x_gor_dot + img->x_gor_step;
			img->y_gor_dot = img->y_gor_dot + img->y_gor_step;
			x = (int)img->x_gor_dot / CUBIK;
			y = (int)img->y_gor_dot / CUBIK;
		}
		else
			break ;
	}
}

void		search_wall_vertical(t_data *img)
{
	int		x;
	int		y;

	x = (int)img->x_vert_dot / CUBIK;
	y = (int)img->y_vert_dot / CUBIK;
	while (y < img->count_line && y > -1 && x > -1 && x < img->map2[y])
	{
		if (img->map[y][x] != '1')
		{
			img->x_vert_dot = img->x_vert_dot + img->x_vert_step;
			img->y_vert_dot = img->y_vert_dot + img->y_vert_step;
			x = (int)img->x_vert_dot / CUBIK;
			y = (int)img->y_vert_dot / CUBIK;
		}
		else
			break ;
	}
}
