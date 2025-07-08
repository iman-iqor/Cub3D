/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:51:17 by imiqor            #+#    #+#             */
/*   Updated: 2025/07/08 22:42:40 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"



void	init_game(t_game *game, t_map *map)
{
	game->win_width = map->map_width * TILE_SIZE;
	game->win_height = map->map_height * TILE_SIZE;
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit("MLX failed to init");
	game->win = mlx_new_window(game->mlx, game->win_width, game->win_height,
			"cub3D");
	if (!game->win)
	{
		mlx_destroy_display(game->mlx);
		error_exit("Failed to open window");
	}
	game->img = mlx_new_image(game->mlx, game->win_width, game->win_height);
	if (!game->img)
		error_exit("mlx_new_image failed");
	game->data_addr = mlx_get_data_addr(game->img, &game->bpp, &game->line_len,
			&game->endian);
	
	game->map = *map;
	// Player starting position (centered inside square)
	game->player_x = map->player_x + 0.5;
	game->player_y = map->player_y + 0.5;
	// Direction depends on the player start orientation
	if (map->player_dir == 'N')
	{
		game->dir_x = 0;
		game->dir_y = -1;
		game->plane_x = 0.66;
		game->plane_y = 0;
	}
	if (map->player_dir == 'S')
	{
		game->dir_x = 0;
		game->dir_y = 1;
		game->plane_x = -0.66;
		game->plane_y = 0;
	}
	if (map->player_dir == 'E')
	{
		game->dir_x = 1;
		game->dir_y = 0;
		game->plane_x = 0;
		game->plane_y = 0.66;
	}
	if (map->player_dir == 'W')
	{
		game->dir_x = -1;
		game->dir_y = 0;
		game->plane_x = 0;
		game->plane_y = -0.66;
	}
}

void	image_failed_to_load(t_game *game)
{
	if (!game->wall_no || !game->wall_so || !game->wall_ea || !game->wall_we)
	{
		if (game->wall_no)
			mlx_destroy_image(game->mlx, game->wall_no);
		if (game->wall_so)
			mlx_destroy_image(game->mlx, game->wall_so);
		if (game->wall_ea)
			mlx_destroy_image(game->mlx, game->wall_ea);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		error_exit("error: could not load one or more images");
	}
}

void	load_images(t_game *game, t_map *map)
{
	int	h;
	int	w;

	(void)map;
	game->wall_no = mlx_xpm_file_to_image(game->mlx, "./textures/north.xpm", &w,
			&h);
	game->wall_so = mlx_xpm_file_to_image(game->mlx, "./textures/south.xpm", &w,
			&h);
	game->wall_we = mlx_xpm_file_to_image(game->mlx, "./textures/west.xpm", &w,
			&h);
	game->wall_no = mlx_xpm_file_to_image(game->mlx, "./textures/east.xpm", &w,
			&h);
	image_failed_to_load(game);
}
void put_pixel(t_game *g, int x, int y, int color)
{
    char *dst;

    // 1) calculate the address of pixel (x,y):
    dst = g->data_addr
        + y * g->line_len               // jump down y rows
        + x * (g->bpp / 8);             // jump right x pixels

    // 2) write your 32‑bit color into that spot:
    *(unsigned int *)dst = color;       // color is 0xRRGGBB
}
void draw_player(t_game *game, t_map *map)
{
    int px = map->player_x * TILE_SIZE;
    int py = map->player_y * TILE_SIZE;
    int size = TILE_SIZE / 4;   // Quarter‑tile square

    int dy = -size;
    while (dy <= size)
    {
        int dx = -size;
        while (dx <= size)
        {
            put_pixel(game, px + dx, py + dy, 0xFF0000);
            dx++;
        }
        dy++;
    }
}

void draw_tile(t_game *g, int x, int y, int color)
{
    int i = 0;
    while (i < TILE_SIZE)
    {
        int j = 0;
        while (j < TILE_SIZE)
        {
            put_pixel(g, x + j, y + i, color);
            j++;
        }
        i++;
    }
}

void	draw_map_and_player(t_game *game, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_grid[i])
	{
		j = 0;
		while (map->map_grid[i][j])
		{
			if (map->map_grid[i][j] == '1')
				draw_tile(game,j*TILE_SIZE,i*TILE_SIZE,0x0000FF);
			else
				draw_tile(game,j*TILE_SIZE,i*TILE_SIZE,0xFFFF00);
			j++;
		}
		i++;
	}
	draw_player(game, map);
	mlx_put_image_to_window(game->mlx,
                        game->win,
                        game->img,
                        0, 0);
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_game	game;

	parssing(&map, argc, argv);
	init_game(&game, &map);
	draw_map_and_player(&game, &map);
	// load_images(&game,&map);
	mlx_loop(game.mlx);
	ft_gc(0, 'f');
	return (0);
}
