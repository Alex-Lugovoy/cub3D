/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screen.m                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsophia <bsophia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:17:13 by bsophia           #+#    #+#             */
/*   Updated: 2021/03/17 19:17:38 by bsophia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#import <AppKit/NSScreen.h>
void	mlx_get_screen_size(int *width, int *height)
{
	NSRect disp = [[NSScreen mainScreen] frame];
	*height = (int)disp.size.height;
	*width = (int)disp.size.width;
}
