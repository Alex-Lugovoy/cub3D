/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsophia <bsophia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:46:22 by bsophia           #+#    #+#             */
/*   Updated: 2021/03/23 21:59:58 by bsophia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void			ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char*)s;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}

void				*ft_calloc(size_t count, size_t size)
{
	char			*p;

	p = malloc(count * size);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, count * size);
	return (p);
}

static char			*cheker(char **save, char **line)
{
	char			*pn;

	pn = NULL;
	if (*save)
	{
		if ((pn = ft_strchrr(*save, '\n')))
		{
			*pn = '\0';
			*line = ft_strdupp(*save);
			*save = ft_strcpyy(*save, ++pn);
		}
		else
		{
			*line = ft_strdupp(*save);
			free(*save);
			*save = NULL;
		}
	}
	else
		*line = ft_calloc(1, 1);
	return (pn);
}

int					get_next_line(int fd, char **line)
{
	static char		*save = NULL;
	char			bufer[BUFFER_SIZE + 1];
	char			*pn;
	int				reader;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 100000000
		|| (read(fd, bufer, 0) < 0))
		return (-1);
	pn = cheker(&save, line);
	while ((!pn && (reader = read(fd, bufer, BUFFER_SIZE))))
	{
		bufer[reader] = '\0';
		if ((pn = ft_strchrr(bufer, '\n')))
		{
			*pn = '\0';
			if (!(save = ft_strdupp(++pn)))
				return (-1);
		}
		if (!(*line = ft_strjoinn(*line, bufer)))
			return (-1);
	}
	if (reader == 0 && !save)
		return (0);
	return (1);
}
