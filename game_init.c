/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjbar <mbenjbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:49:44 by imiqor            #+#    #+#             */
/*   Updated: 2025/10/10 22:14:55 by mbenjbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "header.h"

// void	init_game(t_game *game, t_map *map)
// {
// 	game->win_width = map->map_width * TILE_SIZE;
// 	game->win_height = map->map_height * TILE_SIZE;
	

// 	game->mlx = mlx_init();
// 	if (!game->mlx)
// 		error_exit("MLX failed to init");
// 	game->win = mlx_new_window(game->mlx, game->win_width, game->win_height,
// 			"cub3D");
// 	if (!game->win)
// 	{
// 		mlx_destroy_display(game->mlx);
// 		error_exit("Failed to open window");
// 	}
// 	game->img = mlx_new_image(game->mlx, game->win_width, game->win_height);
// 	if (!game->img)
// 		error_exit("mlx_new_image failed");
// 	game->data_addr = mlx_get_data_addr(game->img, &game->bpp, &game->line_len,
// 			&game->endian);
// 	game->map = *map;
// 	game->player_x = (map->player_x + 0.5) * TILE_SIZE;
// 	game->player_y = (map->player_y + 0.5) * TILE_SIZE;
// 	// Direction depends on the player start orientation
// 	if (map->player_dir == 'N')
// 	{
// 		game->dir_x = 0;
// 		game->dir_y = -1;
// 		game->plane_x = 0.66;
// 		game->plane_y = 0;
// 		game->angle = M_PI/2;
// 	}
// 	if (map->player_dir == 'S')
// 	{
// 		game->dir_x = 0;
// 		game->dir_y = 1;
// 		game->plane_x = -0.66;
// 		game->plane_y = 0;
// 		game->angle= 3*M_PI / 2;
// 	}
// 	if (map->player_dir == 'E')
// 	{
// 		game->dir_x = 1;
// 		game->dir_y = 0;
// 		game->plane_x = 0;
// 		game->plane_y = 0.66;
// 		game->angle = 0;
// 	}
// 	if (map->player_dir == 'W')
// 	{
// 		game->dir_x = -1;
// 		game->dir_y = 0;				
// 		game->plane_x = 0;
// 		game->plane_y = -0.66;
// 		game->angle  = M_PI;
// 	}
// }