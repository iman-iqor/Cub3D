CC = cc  -g3
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS_MAC = -framework OpenGL -framework AppKit -L./minilibx -lmlx
MLX_FLAGS_LINUX = -L./minilibx-linux -lmlx -lXext -lX11
L_FLAGS = -lmlx -lXext -lX11 -lm -lz
SRC = main.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c ./parssing/split.c \
./parssing/argv1.c ./parssing/colors.c ./parssing/map_content.c ./parssing/parse_map1.c \
./parssing/parse_map2.c ./parssing/parse_map3.c \
./parssing/parssing_utils.c   ./parssing/utils.c \
./parssing/textures.c  ./parssing/parse_map4.c ./parssing/ft_gc.c 

NAME  = cube3d
RM = rm -f

all: ${NAME} 

${NAME}: ${SRC}
	make -C ./libft/
	# make -C ./minilibx/  
	${CC} ${SRC} ./libft/libft.a -o $(NAME) ${CFLAGS}  ${MLX_FLAGS_LINUX}


clean:
	make -C ./libft/ clean

fclean: clean
	${RM} $(NAME)
	make -C ./libft/ fclean

re: fclean all