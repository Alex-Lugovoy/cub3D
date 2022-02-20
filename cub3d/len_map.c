/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsophia <bsophia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:09:45 by bsophia           #+#    #+#             */
/*   Updated: 2021/03/23 16:10:01 by bsophia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		len_map(t_data *img)
{
	int	i;

	i = 0;
	if (!(img->map2 = (int*)malloc(sizeof(int) * img->count_line)))
		return (-1);
	while (i < img->count_line)
	{
		img->map2[i] = ft_strlen(img->map[i]);
		i++;
	}
	return (0);
}
