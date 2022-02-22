/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sprite_not_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsophia <bsophia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:37:32 by bsophia           #+#    #+#             */
/*   Updated: 2021/03/24 17:28:42 by bsophia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		checker_sprite(t_data *img)
{
	int			i;

	i = 0;
	img->count_sprite = count_sprites(img);
	if (img->count_sprite == 0)
		return (0);
	if (!(img->sprite = (t_sprite**)malloc(sizeof(t_sprite*) *
		img->count_sprite)))
		return (-1);
	while (i < img->count_sprite)
	{
		if (!(img->sprite[i] = (t_sprite*)malloc(sizeof(t_sprite))))
			return (-1);
		i++;
	}
	if (!(img->sprite[0]->img = mlx_xpm_file_to_image(img->mlx, img->s,
		&img->sprite[0]->width, &img->sprite[0]->height)))
		return (-1);
	if (!(img->sprite[0]->addr = mlx_get_data_addr(img->sprite[0]->img,
		&img->sprite[0]->bpp, &img->sprite[0]->line_length,
		&img->sprite[0]->endian)))
		return (-1);
	return (0);
}

int				find_sprite_not_map(t_list *str, t_data *img)
{
	int			i;

	i = 0;
	while (str)
	{
		if ((str->content)[i] == 'S' && (str->content)[i + 1] != 'O')
		{
			i = 1;
			while ((str->content)[i] == ' ')
				i++;
			if (!(img->s = ft_strdupp((str->content) + i)))
				return (-1);
			if (open(img->s, O_RDONLY) < 0)
				return (-1);
		}
		str = str->next;
	}
	if (img->s == NULL)
		return (-1);
	if (-1 == checker_sprite(img))
		return (-1);
	return (0);
}
