/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsophia <bsophia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 18:08:39 by bsophia           #+#    #+#             */
/*   Updated: 2021/03/23 16:14:34 by bsophia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		count_sprites(t_data *img)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (i < img->count_line)
	{
		while (img->map[i][j])
		{
			if (img->map[i][j] == '2')
				k++;
			j++;
		}
		j = 0;
		i++;
	}
	return (k);
}
