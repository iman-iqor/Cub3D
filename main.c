/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:51:17 by imiqor            #+#    #+#             */
/*   Updated: 2025/07/04 23:39:19 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"

void	check_map_content(char **content, t_map *map)
{
	int	i;

	i = 0;
	parse_textures_and_colors(map->map_two_d, &i, map);
	free(map->no);
	free(map->we);
	free(map->so);
	free(map->ea);
	
	while (content[i] && ft_strcmp(content[i], "\n") == 0)
		i++;
	if (!content[i])
		write(2, "Map doesn't exist!\n", 20);
	check_no_blank_lines_inside_map(content, i);
	parse_map(map,content,i);
}
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
	t_game game;

	ft_memset(&map, 0, sizeof(t_map));
	check_argc(argc);
	check_extention(argv[1]);
	check_if_file_exist(argv[1]);
	get_cub_content(argv[1], &map);
	check_map_content(map.map_two_d, &map);


	/****Start the game*** */
	init_game(&game,&map);
	mlx_loop(game.mlx);

	return (0);
}
