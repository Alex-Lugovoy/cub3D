/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsophia <bsophia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:25:28 by bsophia           #+#    #+#             */
/*   Updated: 2021/03/23 21:05:42 by bsophia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	free_sprite(t_data *img)
{
	int		i;

	i = 0;
	while (i < img->count_sprite)
	{
		free(img->sprite[i]);
		i++;
	}
	if (img->count_sprite > 0)
		free(img->sprite);
}

static void	free_images(t_data *img)
{
	if (img->images != NULL)
	{
		if (img->images[0])
			free(img->images[0]);
		if (img->images[1])
			free(img->images[1]);
		if (img->images[2])
			free(img->images[2]);
		if (img->images[3])
			free(img->images[3]);
	}
	if (img->images != NULL)
		free(img->images);
}

void		free_list(t_list **pars)
{
	t_list *head;
	t_list *tmp;

	head = *pars;
	while (head)
	{
		tmp = head->next;
		free(head->content);
		free(head);
		head = tmp;
	}
}

static void	free_char(t_data *img)
{
	int i;

	i = -1;
	if (img->map)
	{
		while (++i < img->count_line)
			free(img->map[i]);
		free(img->map);
	}
	if (img->map2)
		free(img->map2);
	if (img->dist_luch)
		free(img->dist_luch);
	if (img->so)
		free(img->so);
	if (img->we)
		free(img->we);
	if (img->no)
		free(img->no);
	if (img->ea)
		free(img->ea);
	if (img->s)
		free(img->s);
}

void		free_content(t_data *img)
{
	free_sprite(img);
	free_images(img);
	free_char(img);
	exit(0);
}
