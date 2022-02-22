/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsophia <bsophia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:04:52 by bsophia           #+#    #+#             */
/*   Updated: 2021/03/23 14:43:06 by bsophia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		player(t_data *img, int j, int i, char k)
{
	img->x_gamer = (j + 1) * CUBIK - (CUBIK / 2);
	img->y_gamer = (i + 1) * CUBIK - (CUBIK / 2);
	if (k == 'N')
		img->direction = M_PI / 2;
	if (k == 'S')
		img->direction = 3 * M_PI / 2;
	if (k == 'E')
		img->direction = 0;
	if (k == 'W')
		img->direction = M_PI;
}

int				find_player(t_data *img)
{
	int			i;
	int			j;
	int			k;

	i = -1;
	j = 0;
	k = 0;
	while (++i < img->count_line)
	{
		while (img->map[i][j])
		{
			if (img->map[i][j] == 'N' || img->map[i][j] == 'S' ||
				img->map[i][j] == 'E' || img->map[i][j] == 'W')
			{
				player(img, j, i, img->map[i][j]);
				k++;
			}
			j++;
		}
		j = 0;
	}
	if (k == 1)
		return (0);
	else
		return (-1);
}
