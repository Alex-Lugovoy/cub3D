/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsophia <bsophia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:30:11 by bsophia           #+#    #+#             */
/*   Updated: 2021/03/22 15:39:48 by bsophia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		line_check(char *str)
{
	int			i;

	i = 2;
	while ((str[i] == ' ' || (str[i] >= '0' && str[i] <= '9')) &&
		str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (0);
	else
		return (-1);
}

static int		cifri(char *str, t_data *img)
{
	int			i;
	int			flag;

	i = 2;
	flag = 0;
	while ((str[i] == ' ' || str[i] == '0') && str[i] != '\0')
		i++;
	if (str[i] >= '1' && str[i] <= '9')
		img->wind_width = ft_atoi(str + i, img);
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	while ((str[i] == ' ' || str[i] == '0') && str[i] != '\0')
		i++;
	if (str[i] >= '1' && str[i] <= '9')
		img->wind_height = ft_atoi(str + i, img);
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	if ((img->wind_height == -50 || img->wind_width == -50) &&
		img->wind_height != 0 && img->wind_height != 0)
		mlx_get_screen_size(&img->wind_width, &img->wind_height);
	if (str[i] == '\0')
		return (0);
	else
		return (-1);
}

int				find_window(t_list *str, t_data *img)
{
	int			i;

	i = 0;
	while (str)
	{
		if ((str->content)[i] == 'R' && (str->content)[i + 1] == ' ')
		{
			if (-1 == line_check(str->content))
				return (-1);
			if (-1 == cifri(str->content, img))
				return (-1);
		}
		str = str->next;
	}
	return (0);
}
