/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooki.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsophia <bsophia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:52:21 by bsophia           #+#    #+#             */
/*   Updated: 2021/03/25 10:41:23 by bsophia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		hooki_left(t_data *img)
{
	int		x;
	int		y;

	y = (img->y_gamer + sin(img->direction - M_PI / 2) * STEP) / CUBIK;
	x = (img->x_gamer - cos(img->direction - M_PI / 2) * STEP) / CUBIK;
	if (y < img->count_line && y > -1 && x > -1 && x < img->map2[y] &&
		img->map[(int)(img->y_gamer + ((STEP + 8) * sin(img->direction - M_PI /
		2))) / CUBIK][(int)(img->x_gamer - ((STEP + 8) * cos(img->direction -
		M_PI / 2))) / CUBIK] != '1' && y < img->count_line && y > -1 && x >
		-1 && x < img->map2[y] && img->map[(int)(img->y_gamer + (STEP *
		sin(img->direction - M_PI / 2))) / CUBIK][(int)(img->x_gamer -
		(STEP * cos(img->direction - M_PI / 2))) / CUBIK] != ' ')
	{
		img->y_gamer += sin(img->direction - M_PI / 2) * STEP;
		img->x_gamer -= cos(img->direction - M_PI / 2) * STEP;
	}
}

void		hooki_down(t_data *img)
{
	int		x;
	int		y;

	y = (img->y_gamer + sin(img->direction) * STEP) / CUBIK;
	x = (img->x_gamer - cos(img->direction) * STEP) / CUBIK;
	if (y < img->count_line && y > -1 && x > -1 && x < img->map2[y] &&
		img->map[(int)(img->y_gamer +
		((STEP + 8) * sin(img->direction))) / CUBIK]
		[(int)(img->x_gamer - ((STEP + 8) * cos(img->direction))) / CUBIK] !=
		'1' &&
		y < img->count_line && y > -1 && x > -1 && x < img->map2[y] &&
		img->map[(int)(img->y_gamer +
		(STEP * sin(img->direction))) / CUBIK]
		[(int)(img->x_gamer - (STEP * cos(img->direction))) / CUBIK] != ' ')
	{
		img->y_gamer += sin(img->direction) * STEP;
		img->x_gamer -= cos(img->direction) * STEP;
	}
}

void		hooki_right(t_data *img)
{
	int		x;
	int		y;

	y = (img->y_gamer - sin(img->direction - M_PI / 2) * STEP) / CUBIK;
	x = (img->x_gamer + cos(img->direction - M_PI / 2) * STEP) / CUBIK;
	if (y < img->count_line && y > -1 && x > -1 && x < img->map2[y]
		&& img->map[(int)(img->y_gamer -
		((STEP + 8) * sin(img->direction - M_PI / 2))) / CUBIK][(int)
		(img->x_gamer +
		((STEP + 8) * cos(img->direction - M_PI / 2))) / CUBIK] != '1' &&
		y < img->count_line && y > -1 && x > -1 && x < img->map2[y]
		&& img->map[(int)(img->y_gamer -
		(STEP * sin(img->direction - M_PI / 2))) / CUBIK][(int)(img->x_gamer +
		(STEP * cos(img->direction - M_PI / 2))) / CUBIK] != ' ')
	{
		img->y_gamer -= sin(img->direction - M_PI / 2) * STEP;
		img->x_gamer += cos(img->direction - M_PI / 2) * STEP;
	}
}

void		hooki_up(t_data *img)
{
	int		x;
	int		y;

	y = (img->y_gamer - sin(img->direction) * STEP) / CUBIK;
	x = (img->x_gamer + cos(img->direction) * STEP) / CUBIK;
	if (y < img->count_line && y > -1 && x > -1 && x < img->map2[y] &&
		img->map[(int)(img->y_gamer -
		((STEP + STEP + 6) * sin(img->direction))) / CUBIK][(int)(img->x_gamer +
		((STEP + STEP + 6) * cos(img->direction))) / CUBIK] != '1' &&
		y < img->count_line && y > -1 && x > -1 && x < img->map2[y] &&
		img->map[(int)(img->y_gamer -
		(STEP * sin(img->direction))) / CUBIK][(int)(img->x_gamer +
		(STEP * cos(img->direction))) / CUBIK] != ' ')
	{
		img->y_gamer -= sin(img->direction) * STEP;
		img->x_gamer += cos(img->direction) * STEP;
	}
}
