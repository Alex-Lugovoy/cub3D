/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_butt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsophia <bsophia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 18:13:35 by bsophia           #+#    #+#             */
/*   Updated: 2021/03/22 19:07:32 by bsophia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		press_butt(int keycode, t_data *img)
{
	mlx_clear_window(img->mlx, img->mlx_win);
	if (keycode == 53)
		close123(img);
	if (keycode == 0)
		hooki_left(img);
	if (keycode == 2)
		hooki_right(img);
	if (keycode == 13)
		hooki_up(img);
	if (keycode == 1)
		hooki_down(img);
	if (keycode == 124)
		img->direction -= (2 * M_PI / 180);
	if (keycode == 123)
		img->direction += (2 * M_PI / 180);
	if (img->direction > (2 * M_PI))
		img->direction = img->direction - (2.0 * M_PI);
	if (img->direction < 0)
		img->direction = img->direction + (2.0 * M_PI);
	cast_ray_final2(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}
