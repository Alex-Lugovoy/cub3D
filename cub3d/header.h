/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsophia <bsophia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:57:06 by bsophia           #+#    #+#             */
/*   Updated: 2021/03/25 11:28:43 by bsophia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>

# define CUBIK 64
# define CUBIK_1 64.0
# define BUFFER_SIZE 1
# define STEP 14

typedef struct		s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

typedef struct		s_sprite
{
	double			distanse;
	double			distanse_fabs;
	int				x;
	int				y;
	int				height;
	int				line_length;
	char			*addr;
	int				endian;
	void			*img;
	int				bpp;
	double			sprite_dir;
	int				width;
	double			sprite_size;
}					t_sprite;

typedef struct		s_texture
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				images_width;
	int				images_height;
}					t_texture;

typedef struct		s_data
{
	void			*mlx;
	void			*mlx_win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				texture;
	double			angle;
	int				x_gamer;
	int				y_gamer;
	char			**map;
	double			x_gor_dot;
	double			y_gor_dot;
	double			x_gor_step;
	double			y_gor_step;
	double			x_vert_dot;
	double			y_vert_dot;
	double			x_vert_step;
	double			y_vert_step;
	double			vert_distant;
	double			goriz_distant;
	double			direction;
	double			height_post;
	int				x_for_wall;
	int				count;
	int				end_post;
	int				color;
	double			tex_y;
	double			tex_x;
	double			offset;
	double			save_luch;
	t_sprite		**sprite;
	t_texture		**images;
	int				count_sprite;
	int				num_sp;
	double			*dist_luch;
	char			*so;
	char			*we;
	char			*no;
	char			*ea;
	char			*s;
	int				wind_width;
	int				wind_height;
	double			fi;
	double			sp_ray;
	double			step_x;
	double			num_ray;
	double			step_y;
	int				count_line;
	int				count_atoi;
	int				floor_1;
	int				floor_2;
	int				floor_3;
	int				ceil_1;
	int				ceil_2;
	int				ceil_3;
	int				color_floor;
	int				color_ceil;
	int				*map2;
	double			s_first_vertical;
	double			s_first_goriz;
	double			s_step_xx;
	double			s_step_yy;
	double			s_text_y;
	double			s_text_x;
	int				s_x;
	int				s_y;
	int				s_b;
	int				s_bb;
	int				count_cub;
	int				t;
	int				sor_i;
	int				sor_j;
	int				sor_x;
	int				sor_y;
	double			sor_dis;
}					t_data;

void				search_wall_gorizont(t_data *img);
void				search_wall_vertical(t_data *img);
void				first_hit_gorizont_wall(t_data *img);
void				first_hit_vertical_wall(t_data *img);
void				serch_distanse_to_the_wall(t_data *img);
void				draw_ray(int x1, int y1, int x2, int y2, t_data *img);
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
void				print_slice(t_data *img);
void				find_sprite(t_data *img);
void				add_param_sprite(t_data *img);
void				sort_sprite(t_data *img);
size_t				ft_strlenn(const char *s);
int					ft_strchr(const char *s, int c);
char				*ft_strjoinn(char *s1, char *s2);
char				*ft_strdupp(const char *src);
char				*ft_strcpyy(char *dest, char *src);
int					get_next_line(int fd, char **line);
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstnew(void *content);
int					find_text_not_map(t_list *str, t_data *img);
char				*ft_strchrr(const char *s, int c);
int					ft_atoi(const char *s, t_data *img);
int					color_put_sp(t_data *img, int x, int y);
void				draw_sprite(t_data *img);
int					find_text_not_map(t_list *str, t_data *img);
int					check_texture(t_data *img);
void				null_struct(t_data *img);
int					find_sprite_not_map(t_list *str, t_data *img);
int					ft_lstsize(t_list *lst);
int					create_map(t_list *str, t_data *img);
void				*ft_calloc(size_t count, size_t size);
int					count_sprites(t_data *img);
int					find_window(t_list *str, t_data *img);
void				mlx_get_screen_size(int *width, int *height);
int					find_player(t_data *img);
int					find_fc(t_list *str, t_data *img);
int					ft_atoi_fc(const char *s);
int					create_color(int t, int r, int g, int b);
void				*ft_memset(void *b, int c, size_t len);
int					get_screen(t_data *img);
int					valid_map(t_data *img);
int					ft_strlen(const char *s);
int					len_map(t_data *img);
void				hooki_left(t_data *img);
void				hooki_down(t_data *img);
void				hooki_right(t_data *img);
void				hooki_up(t_data *img);
void				goriz_dist(t_data *img, int *cross);
void				vert_dist(t_data *img, int *cross);
int					press_butt(int keycode, t_data *img);
void				cast_ray_final2(t_data *img);
int					read_file(t_data *img, char *argv);
int					mlx_start(t_data *img);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					check_two_arguments(t_data *img, char *str);
void				i_love_sprite(t_data *img);
int					close123(t_data *img);
void				loop_hook(t_data *img);
int					check_first_argument(char *str);
void				free_content(t_data *img);
void				free_list(t_list **pars);
void				null_images(t_data *img);
int					ft_strcmp(char *str, char *str1);

#endif
