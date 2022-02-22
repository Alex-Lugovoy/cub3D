NAME 	= cub3D

DIR 	= .

LIST 	=	./game/main.c\
			./draw/search_wall.c\
			./draw/first_hit_wall.c\
			./draw/serch_distanse_to_the_wall.c \
			./draw/draw_wall.c \
			./draw/sort_sprite.c \
			./draw/draw_sprite.c \
			./check/find_texture_and_check.c \
			./game/null_struct.c \
			./check/check_texture.c \
			./game/ft_lstadd_back.c \
			./game/ft_lstnew.c \
			./game/get_next_line.c \
			./game/get_next_line_utils.c \
			./draw/find_sprite_not_map.c \
			./game/create_map.c \
			./game/ft_lstsize.c \
			./game/ft_strchr.c \
			./game/find_window.c \
			./game/ft_atoi.c \
			./game/find_player.c \
			./game/find_fc.c \
			./game/ft_atoi_fc.c \
			./game/create_color.c \
			./game/ft_memset.c \
			./game/screen.c \
			./check/map_valid.c \
			./game/ft_strlen.c \
			./game/len_map.c \
			./game/hooki.c \
			./draw/goriz_dist.c \
			./draw/count_sprite.c \
			./draw/add_param_sprite.c \
			./game/press_butt.c \
			./game/read_file.c \
			./game/mlx_start.c \
			./game/ft_strncmp.c \
			./check/check_two_arguments.c \
			./check/check_first_argument.c \
			./draw/i_love_sprite.c \
			./game/loop_hook.c \
			./game/free_content.c \
			./draw/vert_dist.c \
			./game/null_images.c \
			./game/ft_strcmp.c
			./game/ft_strdup.c
			
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
