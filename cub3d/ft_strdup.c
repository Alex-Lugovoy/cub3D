/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsophia <bsophia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:13:58 by bsophia           #+#    #+#             */
/*   Updated: 2021/03/12 15:27:05 by bsophia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*b;

	i = 0;
	while (src[i] != '\0')
		i++;
	b = (char*)malloc(sizeof(char) * (i + 1));
	if (b == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		b[i] = src[i];
		i++;
	}
	b[i] = '\0';
	return (b);
}
