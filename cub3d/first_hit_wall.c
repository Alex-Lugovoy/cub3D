/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_hit_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsophia <bsophia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 18:28:02 by bsophia           #+#    #+#             */
/*   Updated: 2021/03/22 15:41:41 by bsophia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			first_hit_gorizont_wall(t_data *img)
{
	if (img->angle > 0 && img->angle < M_PI)
	{
		img->x_gor_step = CUBIK / tan(img->angle);
		img->y_gor_dot = (int)(img->y_gamer / CUBIK) * CUBIK - 0.00000000001;
		img->x_gor_dot = img->x_gamer + (img->y_gamer - img->y_gor_dot)
			/ tan(img->angle);
		img->y_gor_step = -CUBIK;
	}
	else
	{
		img->x_gor_step = -(CUBIK / tan(img->angle));
		img->y_gor_dot = (int)(img->y_gamer / CUBIK) * CUBIK + CUBIK;
		img->x_gor_dot = img->x_gamer + (img->y_gamer - img->y_gor_dot)
			/ tan(img->angle);
		img->y_gor_step = CUBIK;
	}
}

void			first_hit_vertical_wall(t_data *img)
{
	if (img->angle < M_PI / 2 || img->angle > 3 * M_PI / 2)
	{
		img->x_vert_dot = (int)(img->x_gamer / CUBIK) * CUBIK + CUBIK;
		img->y_vert_dot = img->y_gamer + (img->x_gamer - img->x_vert_dot)
			* tan(img->angle);
		img->x_vert_step = CUBIK;
		img->y_vert_step = -(CUBIK * tan(img->angle));
	}
	else
	{
		img->x_vert_dot = (int)(img->x_gamer / CUBIK) * CUBIK - 0.00000000001;
		img->y_vert_dot = img->y_gamer + (img->x_gamer - img->x_vert_dot)
			* tan(img->angle);
		img->x_vert_step = -CUBIK;
		img->y_vert_step = CUBIK * tan(img->angle);
	}
}
