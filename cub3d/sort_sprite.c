/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsophia <bsophia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 18:50:01 by bsophia           #+#    #+#             */
/*   Updated: 2021/03/23 19:12:29 by bsophia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		sort_sprite(t_data *img)
{
	img->sor_j = img->count_sprite;
	while (img->sor_j - 1)
	{
		img->sor_i = 0;
		while (img->sor_i < img->count_sprite - 1)
		{
			if (img->sprite[img->sor_i]->distanse <
				img->sprite[img->sor_i + 1]->distanse)
			{
				img->sor_x = img->sprite[img->sor_i + 1]->x;
				img->sor_y = img->sprite[img->sor_i + 1]->y;
				img->sor_dis = img->sprite[img->sor_i + 1]->distanse;
				img->sprite[img->sor_i + 1]->distanse =
					img->sprite[img->sor_i]->distanse;
				img->sprite[img->sor_i + 1]->x = img->sprite[img->sor_i]->x;
				img->sprite[img->sor_i + 1]->y = img->sprite[img->sor_i]->y;
				img->sprite[img->sor_i]->x = img->sor_x;
				img->sprite[img->sor_i]->y = img->sor_y;
				img->sprite[img->sor_i]->distanse = img->sor_dis;
			}
			img->sor_i++;
		}
		img->sor_j--;
	}
}
