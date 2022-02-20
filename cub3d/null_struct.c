/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsophia <bsophia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:26:09 by bsophia           #+#    #+#             */
/*   Updated: 2021/03/23 21:06:28 by bsophia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	null_struct(t_data *img)
{
	img->no = NULL;
	img->ea = NULL;
	img->we = NULL;
	img->so = NULL;
	img->s = NULL;
	img->map = NULL;
	img->map2 = NULL;
	img->dist_luch = NULL;
	img->sprite = NULL;
	img->images = NULL;
	img->wind_height = 0;
	img->wind_width = 0;
	img->floor_1 = -1;
	img->floor_2 = -1;
	img->floor_3 = -1;
	img->ceil_1 = -1;
	img->ceil_2 = -1;
	img->ceil_3 = -1;
	img->count_sprite = 0;
}
