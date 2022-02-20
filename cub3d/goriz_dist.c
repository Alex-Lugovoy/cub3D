/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goriz_dist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsophia <bsophia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 18:02:52 by bsophia           #+#    #+#             */
/*   Updated: 2021/03/24 19:15:13 by bsophia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	goriz_dist(t_data *img, int *cross)
{
	img->dist_luch[img->x_for_wall] = img->goriz_distant;
	img->goriz_distant = img->goriz_distant *
		fabs(cos(img->direction - img->angle));
	img->height_post = floor(64.0 / img->goriz_distant *
		(((double)img->wind_width / 2) / tan(M_PI / 6.0)));
	img->offset = (img->x_gor_dot / 64) - (int)(img->x_gor_dot / 64);
	img->tex_x = img->x_gor_dot - ((int)(img->x_gor_dot / 64) *
		64 - 0.00000000001);
	img->save_luch = img->goriz_distant;
	*cross = 2;
}
