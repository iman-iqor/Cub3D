CC = cc  -g3
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS_MAC = -framework OpenGL -framework AppKit -L./minilibx -lmlx
MLX_FLAGS_LINUX = -lmlx -lXext -lX11
SRC = main.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c split.c \
argv1.c colors.c map_content.c parse_map1.c parse_map2.c parse_map3.c utils.c \
textures.c 

NAME  = cube3d
RM = rm -f

all: ${NAME} 

${NAME}: ${SRC}
	make -C ./libft/
	# make -C ./minilibx/  
	${CC} ${SRC} ./libft/libft.a -o $(NAME) ${CFLAGS} #  ${MLX_FLAGS_LINUX}


clean:
	make -C ./libft/ clean

fclean: clean
	${RM} $(NAME)
	make -C ./libft/ fclean

re: fclean all