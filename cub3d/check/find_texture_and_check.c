/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_texture_and_check.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsophia <bsophia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:19:20 by bsophia           #+#    #+#             */
/*   Updated: 2021/03/23 21:05:04 by bsophia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		check_file_ea(char *str, t_data *img)
{
	int			i;

	i = 3;
	while (str[i] == ' ')
		i++;
	if (!(img->ea = ft_strdupp(str + i)))
		return (-1);
	if (open(img->ea, O_RDONLY) < 0)
	{
		printf("Where is the normal file?\n");
		return (-1);
	}
	if (!(img->images[0] = (t_texture*)malloc(sizeof(t_texture))))
		return (-1);
	if (!(img->images[0]->img = mlx_xpm_file_to_image(img->mlx, img->ea,
		&img->images[0]->images_width, &img->images[0]->images_height)))
		return (-1);
	if (!(img->images[0]->addr = mlx_get_data_addr(img->images[0]->img,
		&img->images[0]->bits_per_pixel, &img->images[0]->line_length,
		&img->images[0]->endian)))
		return (-1);
	return (0);
}

static int		check_file_we(char *str, t_data *img)
{
	int			i;

	i = 3;
	while (str[i] == ' ')
		i++;
	if (!(img->we = ft_strdupp(str + i)))
		return (-1);
	if (open(img->we, O_RDONLY) < 0)
	{
		printf("Where is the normal file?\n");
		return (-1);
	}
	if (!(img->images[3] = (t_texture*)malloc(sizeof(t_texture))))
		return (-1);
	if (!(img->images[3]->img = mlx_xpm_file_to_image(img->mlx, img->we,
		&img->images[3]->images_width, &img->images[3]->images_height)))
		return (-1);
	if (!(img->images[3]->addr = mlx_get_data_addr(img->images[3]->img,
		&img->images[3]->bits_per_pixel, &img->images[3]->line_length,
		&img->images[3]->endian)))
		return (-1);
	return (0);
}

static int		check_file_no(char *str, t_data *img)
{
	int			i;

	i = 3;
	while (str[i] == ' ')
		i++;
	if (!(img->no = ft_strdupp(str + i)))
		return (-1);
	if (open(img->no, O_RDONLY) < 0)
	{
		printf("Where is the normal file or press space after NO\n");
		return (-1);
	}
	if (!(img->images[1] = (t_texture*)malloc(sizeof(t_texture))))
		return (-1);
	if (!(img->images[1]->img = mlx_xpm_file_to_image(img->mlx, img->no,
		&img->images[1]->images_width, &img->images[1]->images_height)))
		return (-1);
	if (!(img->images[1]->addr = mlx_get_data_addr(img->images[1]->img,
		&img->images[1]->bits_per_pixel, &img->images[1]->line_length,
		&img->images[1]->endian)))
		return (-1);
	return (0);
}

static int		check_file_so(char *str, t_data *img)
{
	int			i;

	i = 3;
	while (str[i] == ' ')
		i++;
	if (!(img->so = ft_strdupp(str + i)))
		return (-1);
	if (open(img->so, O_RDONLY) < 0)
	{
		printf("Where is the normal file or press space after SO\n");
		return (-1);
	}
	if (!(img->images[2] = (t_texture*)malloc(sizeof(t_texture))))
		return (-1);
	if (!(img->images[2]->img = mlx_xpm_file_to_image(img->mlx, img->so,
		&img->images[2]->images_width, &img->images[2]->images_height)))
		return (-1);
	if (!(img->images[2]->addr = mlx_get_data_addr(img->images[2]->img,
		&img->images[2]->bits_per_pixel, &img->images[2]->line_length,
		&img->images[2]->endian)))
		return (-1);
	return (0);
}

int				find_text_not_map(t_list *str, t_data *img)
{
	int i;

	i = 0;
	if (!(img->images = (t_texture**)malloc(sizeof(t_texture*) * 4)))
		return (-1);
	null_images(img);
	while (str)
	{
		if ((str->content)[i] == 'N' && (str->content)[i + 1] == 'O')
			if (check_file_no(str->content, img) == -1)
				return (-1);
		if ((str->content)[i] == 'S' && (str->content)[i + 1] == 'O')
			if (check_file_so(str->content, img) == -1)
				return (-1);
		if ((str->content)[i] == 'W' && (str->content)[i + 1] == 'E' &&
			(str->content)[i + 2] == ' ')
			if (check_file_we(str->content, img) == -1)
				return (-1);
		if ((str->content)[i] == 'E' && (str->content)[i + 1] == 'A' &&
			(str->content)[i + 2] == ' ')
			if (check_file_ea(str->content, img) == -1)
				return (-1);
		str = str->next;
	}
	return (0);
}
