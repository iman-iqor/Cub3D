/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:51:17 by imiqor            #+#    #+#             */
/*   Updated: 2025/07/07 23:16:04 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"


#include "header.h"

void	init_game(t_game *game, t_map *map)
{
	game->win_width = 640;
	game->win_height = 480;
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit("MLX failed to init");
	game->win = mlx_new_window(game->mlx, game->win_width, game->win_height, "cub3D");
	if (!game->win)
		error_exit("Failed to open window");

	game->map = *map;

	// Player starting position (centered inside square)
	game->player_x = map->player_x + 0.5;
	game->player_y = map->player_y + 0.5;

	// Direction depends on the player start orientation
	if (map->player_dir == 'N') { game->dir_x = 0; game->dir_y = -1; game->plane_x = 0.66; game->plane_y = 0; }
	if (map->player_dir == 'S') { game->dir_x = 0; game->dir_y = 1; game->plane_x = -0.66; game->plane_y = 0; }
	if (map->player_dir == 'E') { game->dir_x = 1; game->dir_y = 0; game->plane_x = 0; game->plane_y = 0.66; }
	if (map->player_dir == 'W') { game->dir_x = -1; game->dir_y = 0; game->plane_x = 0; game->plane_y = -0.66; }
}



int	main(int argc, char **argv)
{
	t_map	map;
	// t_game game;
	parssing(&map,argc,argv);
	


	/****Start the game*** */
	// init_game(&game,&map);
	// mlx_loop(game.mlx);
	ft_gc(0,'f');
	return (0);
}
