/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsophia <bsophia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:44:32 by bsophia           #+#    #+#             */
/*   Updated: 2021/03/22 18:00:53 by bsophia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

size_t		ft_strlenn(const char *s)
{
	size_t i;

	i = 0;
	if (s == NULL)
		return (0);
	if (s[0] == '\0')
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char		*ft_strchrr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	while (*p != '\0')
	{
		if (*p == c)
			return (p);
		p++;
	}
	if (*p == c)
		return (p);
	return (NULL);
}

char		*ft_strjoinn(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	result = malloc(ft_strlenn(s1) + ft_strlenn(s2) + 1);
	if (!result)
		return (NULL);
	while (s1[i] != '\0')
		result[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		result[j++] = s2[i++];
	result[j] = '\0';
	free(s1);
	s1 = NULL;
	return (result);
}

char		*ft_strdupp(const char *src)
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

char		*ft_strcpyy(char *dest, char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == '\0')
		dest[i] = src[i];
	return (dest);
}
