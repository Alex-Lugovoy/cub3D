NAME 	= cub3D

DIR 	= .

LIST 	=	main.c\
			search_wall.c\
			first_hit_wall.c\
			serch_distanse_to_the_wall.c \
			draw_wall.c \
			sort_sprite.c \
			draw_sprite.c \
			find_texture_and_check.c \
			null_struct.c \
			check_texture.c \
			ft_lstadd_back.c \
			ft_lstnew.c \
			get_next_line.c \
			get_next_line_utils.c \
			find_sprite_not_map.c \
			create_map.c \
			ft_lstsize.c \
			ft_strchr.c \
			find_window.c \
			ft_atoi.c \
			find_player.c \
			find_fc.c \
			ft_atoi_fc.c \
			create_color.c \
			ft_memset.c \
			screen.c \
			map_valid.c \
			ft_strlen.c \
			len_map.c \
			hooki.c \
			goriz_dist.c \
			count_sprite.c \
			add_param_sprite.c \
			press_butt.c \
			read_file.c \
			mlx_start.c \
			ft_strncmp.c \
			check_two_arguments.c \
			check_first_argument.c \
			i_love_sprite.c \
			loop_hook.c \
			free_content.c \
			vert_dist.c \
			null_images.c \
			ft_strcmp.c
			
OBJ 	=	$(LIST:.c=.o)

MLX		= ./mlx/

FLAGS 	= -Wall -Wextra -Werror -I$(DIR)
CC		= gcc

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		make -C $(MLX)
		$(CC) $(FLAGS) ./mlx/libmlx.a get_screen.m -Lmlx -lmlx -framework OpenGL -framework Appkit -O3 $(OBJ) -o $(NAME) #-fsanitize=address
clean:
	rm -f $(OBJ)
	make clean -C $(MLX)

fclean: clean
	rm -f $(NAME)
	make clean -C $(MLX)

re: fclean all

.PHONY: all clean fclean re bonus
