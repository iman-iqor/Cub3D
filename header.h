/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjbar <mbenjbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:50:48 by imiqor            #+#    #+#             */
/*   Updated: 2025/10/18 23:02:19 by mbenjbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "./parssing/get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <stdbool.h>

#define TILE_SIZE 60
# define M_PI 3.14159265358979323846
# define ESC_KEY 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define SPACE 32
#define LEFT_ARROW  65361   // XK_Left
#define RIGHT_ARROW 65363   // XK_Right
# define WINDOW_WIDTH 1400
# define WINDOW_HEIGHT 600
# define STEP 8


typedef struct s_state
{
	int			i;
	int			cw;
	int			start;
	int			end;
	int			k;
	char		**two_d;
}				t_state;

typedef struct s_gc
{
	void		*ptr;
	struct s_gc	*next;
}				t_gc;

typedef struct s_map
{
	int			line_count;
	int			grid_lines_count;
	int			map_width;
	int			start_of_map;
	char		**map_two_d;
	char		**map_grid;
	float		player_x;
	float		player_y;
	char		player_dir;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int has_no, has_so, has_we, has_ea;
	int has_floor, has_ceiling;
	unsigned int	floor_color;
	unsigned int	ceiling_color;
}				t_map;

typedef	struct s_distance
{
	double	h_hitx;
	double	xh_step;
	double	h_hity;
	double	yh_step;

	double	v_hitx;
	double	xv_step;
	double	v_hity;
	double	yv_step;
} t_distance;


typedef struct s_texture
{
	void	*textu;
	char	*address;
	int		endian;
	int		width;
	int		height;
	int		lenght;
	int		bpp;
}		t_texture;

typedef struct s_game
{
	void		*mlx;
	void 		*win;
	t_map 		*map;
	char		**grid;
	int			map_height;
	int			map_width;
	double		p_x;
	double		p_y;
	double		angle;
	double		cur_angle;
	int			cur_column;
	double		fov;
	double		rot_angle;
	double		wall_distance;
	t_distance	*dist;
	double		height_wall;
	void		*img;
    char    	*data_addr;
    int     	bpp;
    int     	line_len;
    int     	endian;
	int  		key_up;
    int  		key_down;
    int  		key_left;
    int  		key_right;
    int  		rot_left;
    int  		rot_right;
	t_texture	textures[4];
	int			text_column;
	int			text_index;
	int			flag; //1 if horizontal closer
}				t_game;

/******  Splits  ****** */
char			*ft_strncopy(char *str, int start, int end);
int				count_word(char *args, char sep);
void			init_state(t_state *state, char *args, char sep);
char			**split_lines(char *args, char sep);
/******  TEXTURES   ****** */
void			check_path(char *path);
char			*trim_spaces_end(char *str);
void			assign_texture(t_map *map, char *line, char **dest, char *id);
void			parse_textures_and_colors(char **lines, int *i, t_map *map);
/******  COLORS   ****** */
int				parse_rgb(char *line, int *r, int *g, int *b);
void			set_floor_color(t_map *map, char *line);
void			set_ceiling_color(t_map *map, char *line);
/******  Parssing  ****** */
void			parssing(t_map *map, int argc, char **argv);
void			check_map_content(char **content, t_map *map);
void			check_if_file_exist(char *argv);
void			check_extention(char *argv);
void			check_argc(int argc);
/******  MAP_CONTENT  ****** */
int				nbr_of_lines(char *filename);
void			get_cub_content(char *argv, t_map *map);
/******  PARSE_MAP  ****** */
int				count_map_lines(char **content, int start);
void			trim_newline(char *str);
int				contains_zero(char *line);
void			store_map_lines(char **content, int start, t_map *map);
int				is_valid_map_char(char c);
void			validate_map_chars(t_map *map);
void			validate_walls(t_map *map);
int				ft_check_is_player(char c);
void			parse_map(t_map *map, char **content, int start);
/******  UTILS  ****** */
int				ft_strcmp(char *s1, char *s2);
int				is_blank(char *s);
void			check_no_blank_lines_inside_map(char **content, int start);
char			*ftt_strdup(const char *s1);
/******  GARBAGE_COLLECTOR ****** */
void			add(t_gc **gc, t_gc *new);
t_gc			*create(void *ptr);
void			fr_ee(t_gc *gc);
void			*ft_gc(size_t n, char flag);

/******  DRAW_MAP ****** */
void	draw_map_and_player(t_game *game, t_map *map);
void	draw_tile(t_game *g, int x, int y, int color);
void	draw_player(t_game *game, t_map *map);
void	put_pixel(t_game *g, int x, int y, int color);
/******  LOAD_IMAGES ****** */
void	image_failed_to_load(t_game *game);
void	load_images(t_game *game, t_map *map);
/******  LOAD_IMAGES ****** */
void	init_game(t_game *game, t_map *map);



/******  Raycasting Simo   ****** */
void    game_init(t_game *game);
void	error_exit(char *msg, t_game *game);
void    rendering(t_game *game);
void    normalize(double *angle);
void    hori_first_inter(t_game *game);
void    verti_first_inter(t_game *game);
void    find_wall(t_game *game);
void    final_distance(t_game *game);
void    draw(t_game *game);
int		key_press(int key, void *param);
int		key_release(int key, void *param);
int 	render_frame(void *param);
int 	found(t_game *game, int x, int y);
int 	up(double angle);
int 	down(double angle);
int 	right(double angle);
int 	left(double angle);

#endif