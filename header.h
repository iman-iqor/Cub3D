#ifndef HEADER_H
#define HEADER_H
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"

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
	char	**map_two_d2;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		total_c;
	int		c_count;
	char	*lines;

}			t_map;
#endif