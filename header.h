#ifndef HEADER_H
# define HEADER_H
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_state
{
	int		i;
	int		cw;
	int		start;
	int		end;
	int		k;
	char	**two_d;
}			t_state;

typedef struct s_map
{
	int		fd;
	int		line_count;
	char	**map_two_d;
	char** map_grid;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	char	*lines;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int has_no, has_so, has_we, has_ea;
	int has_floor, has_ceiling;
	int floor_r,floor_g,floor_b;
	int ceiling_r,ceiling_g,ceiling_b;
}			t_map;
/******  SPLIT   ****** */
char		*ftt_free(char **arr);
char		*ft_strncopy(char *str, int start, int end);
int			count_word(char *args, char sep);
void		init_state(t_state *state, char *args, char sep);
char		**split_lines(char *args, char sep);
#endif