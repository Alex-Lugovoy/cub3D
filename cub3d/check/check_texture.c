/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsophia <bsophia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:29:53 by bsophia           #+#    #+#             */
/*   Updated: 2021/03/23 21:03:20 by bsophia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check_texture(t_data *img)
{
	if (img->so == NULL || img->s == NULL || img->ea == NULL || img->we == NULL
		|| img->no == NULL)
	{
		return (-1);
		printf("I can't see the texture\n");
	}
	if (img->wind_width == 0 || img->wind_height == 0)
	{
		printf("You forgot to specify the screen size or not...\n");
		return (-1);
	}
	if (img->floor_1 < 0 || img->floor_2 < 0 || img->floor_3 < 0 ||
		img->ceil_1 < 0 || img->ceil_2 < 0 || img->ceil_3 < 0)
	{
		printf("The floor or ceiling is a strange color\n");
		return (-1);
	}
	if (img->floor_1 > 255 || img->floor_2 > 255 || img->floor_3 > 255 ||
		img->ceil_1 > 255 || img->ceil_2 > 255 || img->ceil_3 > 255)
	{
		printf("The floor or ceiling is a strange color\n");
		return (-1);
	}
	return (0);
}
