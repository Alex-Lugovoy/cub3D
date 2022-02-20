/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsophia <bsophia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:45:27 by bsophia           #+#    #+#             */
/*   Updated: 2021/03/23 19:17:47 by bsophia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			read_file(t_data *img, char *argv)
{
	t_list	*pars;
	int		fd;
	char	*line;

	line = NULL;
	pars = NULL;
	if (0 > (fd = open(argv, O_RDONLY)))
		return (-1);
	while (get_next_line(fd, &line))
		ft_lstadd_back(&pars, ft_lstnew(line));
	ft_lstadd_back(&pars, ft_lstnew(line));
	null_struct(img);
	if (-1 == create_map(pars, img) || -1 == find_text_not_map(pars, img) ||
		find_sprite_not_map(pars, img) == -1 || -1 == find_window(pars, img) ||
		-1 == find_fc(pars, img) || -1 == find_player(img) ||
		-1 == len_map(img) || -1 == valid_map(img) || -1 == check_texture(img))
	{
		free_list(&pars);
		return (-1);
	}
	free_list(&pars);
	return (0);
}
