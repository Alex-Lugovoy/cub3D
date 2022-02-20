/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_dist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsophia <bsophia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:53:32 by bsophia           #+#    #+#             */
/*   Updated: 2021/03/24 19:15:17 by bsophia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	vert_dist(t_data *img, int *cross)
{
	img->dist_luch[img->x_for_wall] = img->vert_distant;
	img->vert_distant = img->vert_distant *
		fabs(cos(img->direction - img->angle));
	img->height_post = floor(64.0 / img->vert_distant *
		(((double)img->wind_width / 2) / tan(M_PI / 6.0)));
	img->offset = (img->y_vert_dot / 64) - (int)(img->y_vert_dot / 64);
	img->tex_x = img->y_vert_dot -
		((int)(img->y_vert_dot / 64) * 64 - 0.00000000001);
	*cross = 1;
	img->save_luch = img->vert_distant;
}
