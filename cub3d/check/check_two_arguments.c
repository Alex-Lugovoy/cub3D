/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_two_arguments.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsophia <bsophia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 20:11:04 by bsophia           #+#    #+#             */
/*   Updated: 2021/03/23 21:57:59 by bsophia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check_two_arguments(t_data *img, char *str)
{
	int i;

	i = ft_strcmp("--save", str);
	if (i == 0)
	{
		get_screen(img);
		return (0);
	}
	printf("Do you think I'm a completely stupid program?\n");
	return (-1);
}
