/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsophia <bsophia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:19:10 by bsophia           #+#    #+#             */
/*   Updated: 2021/03/23 18:23:44 by bsophia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	null_images(t_data *img)
{
	img->images[0] = NULL;
	img->images[1] = NULL;
	img->images[2] = NULL;
	img->images[3] = NULL;
}
