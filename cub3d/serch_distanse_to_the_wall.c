/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serch_distanse_to_the_wall.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsophia <bsophia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 19:39:30 by bsophia           #+#    #+#             */
/*   Updated: 2021/03/22 15:51:48 by bsophia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	serch_distanse_to_the_wall(t_data *img)
{
	img->vert_distant = sqrt((img->x_gamer - img->x_vert_dot) * (img->x_gamer -
	img->x_vert_dot) + (img->y_gamer - img->y_vert_dot) *
	(img->y_gamer - img->y_vert_dot));
	img->goriz_distant = sqrt((img->x_gamer - img->x_gor_dot) * (img->x_gamer -
	img->x_gor_dot) + (img->y_gamer - img->y_gor_dot) *
	(img->y_gamer - img->y_gor_dot));
	if (img->y_vert_dot < 0 || img->x_vert_dot < 0)
		img->vert_distant = INFINITY;
	else if (img->y_gor_dot < 0 || img->x_gor_dot < 0)
		img->goriz_distant = INFINITY;
}
