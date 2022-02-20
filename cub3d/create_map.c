/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsophia <bsophia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 20:07:53 by bsophia           #+#    #+#             */
/*   Updated: 2021/03/23 19:14:17 by bsophia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		make_map(t_list *str1, t_data *img, int size)
{
	int			i;
	int			flag;
	int			j;

	i = 0;
	flag = 0;
	j = 0;
	img->count_line = 0;
	if (!(img->map = ft_calloc(size + 1, sizeof(char *))))
		return (-1);
	while (str1)
	{
		img->map[i] = ft_strdupp(str1->content);
		i++;
		img->count_line++;
		str1 = str1->next;
	}
	return (0);
}

int				create_map(t_list *str, t_data *img)
{
	int			j;
	t_list		*str1;

	str1 = str;
	j = 0;
	while (j != 8 && str1)
	{
		if ((str1->content)[0] == 'W' || (str1->content)[0] == 'N' ||
			(str1->content)[0] == 'E' || (str1->content)[0] == 'R' ||
			(str1->content)[0] == 'C' || (str1->content)[0] == 'F')
			j++;
		if ((str1->content)[0] == 'S' && (str1->content)[0 + 1] == 'O')
			j++;
		if ((str1->content)[0] == 'S' && (str1->content)[0 + 1] == ' ')
			j++;
		str1 = str1->next;
	}
	if (j == 8 && 0 == make_map(str1, img, ft_lstsize(str1)))
		return (0);
	else
	{
		printf("It looks like you forgot to specify the parameters\n");
		return (-1);
	}
}
