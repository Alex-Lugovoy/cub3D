/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_love_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsophia <bsophia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 13:56:53 by bsophia           #+#    #+#             */
/*   Updated: 2021/03/23 18:23:02 by bsophia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	i_love_sprite(t_data *img)
{
	int	i;

	i = 0;
	add_param_sprite(img);
	sort_sprite(img);
	while (i < img->count_sprite)
	{
		img->num_sp = i;
		draw_sprite(img);
		i++;
	}
}
