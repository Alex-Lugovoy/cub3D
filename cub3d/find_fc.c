/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_fc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsophia <bsophia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:39:22 by bsophia           #+#    #+#             */
/*   Updated: 2021/03/23 19:03:55 by bsophia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		check_zap(char *str)
{
	int			i;
	int			flag;

	i = 2;
	flag = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ',')
			flag++;
		i++;
	}
	if (flag != 2)
		return (-1);
	else
		return (0);
}

static int		ceil_color(char *str, t_data *img)
{
	img->t = 2;
	while (str[img->t] == ' ' && str[img->t] != '\0')
		img->t++;
	if (str[img->t] >= '0' && str[img->t] <= '9')
		img->ceil_1 = ft_atoi_fc(str + img->t);
	while (str[img->t] >= '0' && str[img->t] <= '9' && str[img->t] != '\0')
		img->t++;
	while ((str[img->t] == ' ' || str[img->t] == ',') && str[img->t] != '\0')
		img->t++;
	if (str[img->t] >= '0' && str[img->t] <= '9')
		img->ceil_2 = ft_atoi_fc(str + img->t);
	while (str[img->t] >= '0' && str[img->t] <= '9' && str[img->t] != '\0')
		img->t++;
	while ((str[img->t] == ' ' || str[img->t] == ',') && str[img->t] != '\0')
		img->t++;
	if (str[img->t] >= '0' && str[img->t] <= '9')
		img->ceil_3 = ft_atoi_fc(str + img->t);
	while (str[img->t] >= '0' && str[img->t] <= '9' && str[img->t] != '\0')
		img->t++;
	while (str[img->t] == ' ' && str[img->t] != '\0')
		img->t++;
	if (str[img->t] == '\0')
		return (0);
	else
		return (-1);
}

static int		floor_color(char *str, t_data *img)
{
	img->t = 2;
	while (str[img->t] == ' ' && str[img->t] != '\0')
		img->t++;
	if (str[img->t] >= '0' && str[img->t] <= '9')
		img->floor_1 = ft_atoi_fc(str + img->t);
	while (str[img->t] >= '0' && str[img->t] <= '9' && str[img->t] != '\0')
		img->t++;
	while ((str[img->t] == ' ' || str[img->t] == ',') && str[img->t] != '\0')
		img->t++;
	if (str[img->t] >= '0' && str[img->t] <= '9')
		img->floor_2 = ft_atoi_fc(str + img->t);
	while (str[img->t] >= '0' && str[img->t] <= '9' && str[img->t] != '\0')
		img->t++;
	while ((str[img->t] == ' ' || str[img->t] == ',') && str[img->t] != '\0')
		img->t++;
	if (str[img->t] >= '0' && str[img->t] <= '9')
		img->floor_3 = ft_atoi_fc(str + img->t);
	while (str[img->t] >= '0' && str[img->t] <= '9' && str[img->t] != '\0')
		img->t++;
	while (str[img->t] == ' ' && str[img->t] != '\0')
		img->t++;
	if (str[img->t] == '\0')
		return (0);
	else
		return (-1);
}

int				find_fc(t_list *str, t_data *img)
{
	int			i;

	i = 0;
	while (str)
	{
		if ((str->content)[i] == 'F' && (str->content)[i + 1] == ' ')
		{
			if (-1 == floor_color(str->content, img))
				return (-1);
			if (-1 == check_zap(str->content))
				return (-1);
		}
		if ((str->content)[i] == 'C' && (str->content)[i + 1] == ' ')
		{
			if (-1 == ceil_color(str->content, img))
				return (-1);
			if (-1 == check_zap(str->content))
				return (-1);
		}
		str = str->next;
	}
	img->color_ceil = create_color(0, img->ceil_1, img->ceil_2, img->ceil_2);
	img->color_floor = create_color(0, img->floor_1, img->floor_1,
		img->floor_3);
	return (0);
}
