/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsophia <bsophia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:25:57 by bsophia           #+#    #+#             */
/*   Updated: 2021/03/23 21:33:50 by bsophia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		create_3(t_data *img, int fd)
{
	int			cifcif[3];

	cifcif[0] = img->wind_height - 1;
	while (cifcif[0] >= 0)
	{
		cifcif[1] = 0;
		while (cifcif[1] < img->wind_width)
		{
			cifcif[2] = *(int*)(img->addr + (cifcif[0] * img->line_length +
				cifcif[1] * (img->bits_per_pixel / 8)));
			write(fd, &cifcif[2], 3);
			cifcif[1]++;
		}
		cifcif[0]--;
	}
}

static void		screenp(t_data *img, int dimension, char *induct, int f)
{
	if (f == 1)
	{
		induct[3] = dimension >> 8;
		induct[4] = dimension >> 16;
		induct[5] = dimension >> 24;
		induct[10] = 54;
		induct[14] = 40;
	}
	if (f == 2)
	{
		induct[23] = img->wind_height >> 8;
		induct[24] = img->wind_height >> 16;
		induct[25] = img->wind_height >> 24;
	}
}

static void		create_2(t_data *img, char *induct)
{
	induct[18] = img->wind_width;
	induct[19] = img->wind_width >> 8;
	induct[20] = img->wind_width >> 16;
	induct[21] = img->wind_width >> 24;
	induct[22] = img->wind_height;
	screenp(img, 0, induct, 2);
}

static void		create_1(t_data *img, int dimension, int fd)
{
	char		induct[54];

	ft_memset(induct, 0, 54);
	induct[0] = 'B';
	induct[1] = 'M';
	induct[2] = dimension;
	if (fd > 0)
		screenp(img, dimension, induct, 1);
	induct[26] = 1;
	induct[28] = 24;
	create_2(img, induct);
	write(fd, induct, 54);
	create_3(img, fd);
}

int				get_screen(t_data *img)
{
	int			fd;
	int			dimension;
	int			save_width;

	save_width = img->wind_width;
	while (save_width % 4 != 0)
		save_width--;
	dimension = 54 + (4 * save_width * img->wind_height);
	if (!(fd = open("my_first_time.bmp", O_WRONLY | O_CREAT | O_TRUNC
		| O_APPEND, 0666)))
		return (-1);
	create_1(img, dimension, fd);
	close(fd);
	return (0);
}
