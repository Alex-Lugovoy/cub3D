/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsophia <bsophia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 21:51:18 by bsophia           #+#    #+#             */
/*   Updated: 2021/03/23 21:59:33 by bsophia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_strcmp(char *str, char *str1)
{
	int	i;

	i = 0;
	while (str[i] && str1[i])
	{
		if (str[i] == str1[i])
			i++;
		else
			return (-1);
	}
	if (str[i] == '\0' && str1[i] != '\0')
		return (-1);
	if (str[i] != '\0' && str1[i] == '\0')
		return (-1);
	return (0);
}
