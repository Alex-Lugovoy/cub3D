/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsophia <bsophia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:56:13 by bsophia           #+#    #+#             */
/*   Updated: 2021/03/18 17:03:03 by bsophia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	ft_isspace(int s)
{
	if ((s == ' ' || s == '\v' || s == '\t' || s == '\f'
		|| s == '\n' || s == '\r') && s != '\0')
		return (1);
	else
		return (0);
}

int			ft_atoi(const char *s, t_data *img)
{
	int		i;
	int		cif;

	i = 0;
	cif = 0;
	img->count_atoi = 0;
	while (1 == ft_isspace(s[i]) && s[i] != '\0')
		i++;
	if ((s[i] == '+' || s[i] == '-') && s[i] != '\0')
		return (-1);
	while (s[i] >= '0' && s[i] <= '9' && s[i] != '\0')
	{
		cif = (cif * 10) + (s[i] - 48);
		i++;
		img->count_atoi++;
		if (img->count_atoi == 5)
			return (-50);
	}
	return (cif);
}
