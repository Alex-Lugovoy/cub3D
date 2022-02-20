/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsophia <bsophia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:03:46 by bsophia           #+#    #+#             */
/*   Updated: 2021/03/22 15:46:29 by bsophia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	loop_hook(t_data *img)
{
	mlx_hook(img->mlx_win, 2, (1L << 0), &press_butt, img);
	mlx_hook(img->mlx_win, 17, 0, close123, img);
	mlx_loop(img->mlx);
}
