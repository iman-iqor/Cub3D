/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:50:48 by imiqor            #+#    #+#             */
/*   Updated: 2025/07/03 00:50:49 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



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
	int grid_lines_count;
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
/******  TEXTURES   ****** */
void	check_path(char *path);
char	*trim_spaces_end(char *str);
void	assign_texture(t_map *map,char *line, char **dest, char *id);
void	parse_textures_and_colors(char **lines, int *i, t_map *map);
/******  COLORS   ****** */
int	parse_rgb(char *line, int *r, int *g, int *b);
void	set_floor_color(t_map *map, char *line);
void	set_ceiling_color(t_map *map, char *line);
/******  ARGV1  ****** */
int	check_if_file_exist(char *argv);
void	check_extention(char *argv);
void	check_argc(int argc);
/******  MAP_CONTENT  ****** */
int	nbr_of_lines(char *filename);
void	get_cub_content(char *argv, t_map *map);
/******  PARSE_MAP  ****** */
int count_map_lines(char **content, int start);
void trim_newline(char *str);
int contains_zero(char *line);
void store_map_lines(char **content, int start, t_map *map);
int is_valid_map_char(char c);
void validate_map_chars(t_map *map);
void validate_walls(t_map *map);
void parse_map(t_map *map, char **content, int start);
/******  UTILS  ****** */
char	*ft_ssstrjoin(char *save, char *buff);
int	ft_strcmp(char *s1, char *s2);
int	ft_strcmp(char *s1, char *s2);
void	error_exit(char *msg);
int	is_blank(char *s);
void check_no_blank_lines_inside_map(char **content, int start);

#endif