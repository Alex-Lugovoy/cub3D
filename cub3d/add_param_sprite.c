/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_param_sprite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsophia <bsophia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 18:10:39 by bsophia           #+#    #+#             */
/*   Updated: 2021/03/23 16:14:03 by bsophia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	add_param_sprite(t_data *img)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = 0;
	k = 0;
	while (++i < img->count_line)
	{
		while (img->map[i][j])
		{
			if (img->map[i][j] == '2')
			{
				img->sprite[k]->x = (j + 1) * CUBIK - (CUBIK / 2);
				img->sprite[k]->y = (i + 1) * CUBIK - (CUBIK / 2);
				img->sprite[k]->distanse = sqrt((img->x_gamer -
				img->sprite[k]->x) * (img->x_gamer - img->sprite[k]->x) +
				(img->y_gamer - img->sprite[k]->y) *
				(img->y_gamer - img->sprite[k]->y));
				k++;
			}
			j++;
		}
		j = 0;
	}
}
