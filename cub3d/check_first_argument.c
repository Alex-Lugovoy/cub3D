/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_first_argument.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsophia <bsophia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:09:19 by bsophia           #+#    #+#             */
/*   Updated: 2021/03/23 16:31:05 by bsophia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check_first_argument(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
		i++;
	i--;
	if (str[i--] == 'b')
		j++;
	if (str[i--] == 'u')
		j++;
	if (str[i--] == 'c')
		j++;
	if (str[i] == '.')
		j++;
	if (j == 4)
		return (0);
	else
	{
		printf("I couldn't find .cub can you already write normally?\n");
		return (-1);
	}
}
