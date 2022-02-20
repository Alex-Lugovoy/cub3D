/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsophia <bsophia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 20:29:37 by bsophia           #+#    #+#             */
/*   Updated: 2021/03/23 18:00:42 by bsophia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		check_map_left(t_data *img, int j, int i)
{
	while (i > -1 && img->map[j][i])
	{
		if (img->map[j][i] == ' ')
			return (-1);
		if (img->map[j][i] == '1')
			return (0);
		i--;
	}
	printf("Give me a normal card stop torturing me\n");
	return (-1);
}

static int		check_map_right(t_data *img, int j, int i)
{
	while (img->map[j][i])
	{
		if (img->map[j][i] == ' ')
			return (-1);
		if (img->map[j][i] == '1')
			return (0);
		i++;
	}
	printf("Give me a normal card stop torturing me\n");
	return (-1);
}

static int		check_map_down(t_data *img, int j, int i)
{
	while (j < img->count_line && img->map[j][i])
	{
		if (img->map[j][i] == ' ')
			return (-1);
		if (img->map[j][i] == '1')
			return (0);
		j++;
	}
	printf("Give me a normal card stop torturing me\n");
	return (-1);
}

static int		check_map_up(t_data *img, int j, int i)
{
	if (img->map[j][i] != '0' && img->map[j][i] != '2' && img->map[j][i]
		!= 'W' && img->map[j][i] != 'E' && img->map[j][i] != 'N' &&
		img->map[j][i] != 'S')
		return (-1);
	while (j > -1 && img->map[j][i])
	{
		if (img->map[j][i] == ' ')
			return (-1);
		if (img->map[j][i] == '1')
			return (0);
		j--;
	}
	printf("Give me a normal card stop torturing me\n");
	return (-1);
}

int				valid_map(t_data *img)
{
	int			i;
	int			j;

	i = 0;
	j = -1;
	while (++j < img->count_line)
	{
		while (img->map[j][i] != '\0')
		{
			if (img->map[j][i] != '1' && img->map[j][i] != ' ')
			{
				if (-1 == check_map_up(img, j, i))
					return (-1);
				if (-1 == check_map_down(img, j, i))
					return (-1);
				if (-1 == check_map_left(img, j, i))
					return (-1);
				if (-1 == check_map_right(img, j, i))
					return (-1);
			}
			i++;
		}
		i = 0;
	}
	return (0);
}
