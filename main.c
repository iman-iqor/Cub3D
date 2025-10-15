/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjbar <mbenjbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:51:17 by imiqor            #+#    #+#             */
/*   Updated: 2025/10/11 09:43:38 by mbenjbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// bool touch(float px,float py,t_game *game)
// {
// 	int x;
// 	int y;
// 	x = (int)px/TILE_SIZE;
// 	y = (int)py/TILE_SIZE;
	 
// 	if(game->map.map_grid[y][x] == '1')
// 		return true;
// 	return false;
// }
// void move_rotate_player(t_game *game)
// {
// 	float new_x, new_y;
// 	game->move_speed = 0.01;
// 	game->angle_speed = 0.01;

// 	if (game->rot_left) game->angle -= game->angle_speed;
// 	if (game->rot_right) game->angle += game->angle_speed;
// 	if (game->angle < 0) game->angle += 2 * M_PI;
// 	if (game->angle >= 2 * M_PI) game->angle -= 2 * M_PI;
// 	if (game->key_left)
// 	{
// 		new_x = game->map.player_x - sin(game->angle) * game->move_speed;
// 		new_y = game->map.player_y + cos(game->angle) * game->move_speed;
// 	}
// 	else if (game->key_right)				
// 	{
// 		new_x = game->map.player_x + sin(game->angle) * game->move_speed;
// 		new_y = game->map.player_y - cos(game->angle) * game->move_speed;
// 	}
// 	else if (game->key_up)
// 	{
// 		new_x = game->map.player_x - cos(game->angle) * game->move_speed;
// 		new_y = game->map.player_y - sin(game->angle) * game->move_speed;
// 	}
// 	else if (game->key_down)
// 	{
// 		new_x = game->map.player_x + cos(game->angle) * game->move_speed;
// 		new_y = game->map.player_y + sin(game->angle) * game->move_speed;
// 	}
// 	else
// 	{
// 		return; 
// 	}

// 	if (game->map.map_grid[(int)new_y][(int)new_x] == '0')
// 	{
// 		game->map.player_x = new_x;
// 		game->map.player_y = new_y;
// 	}
	
// 	mlx_clear_window(game->mlx, game->win);
// }
// int	render_frame(t_game *game)
// {
	
// 	game->cos_angle = cos(game->angle);
// 	game->sin_angle = sin(game->angle);
// 	game->ray_x = game->player_x;
// 	game->ray_y = game->player_y;
	
	

// 	move_rotate_player(game);

// 	draw_map_and_player(game, &game->map);
// 	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
// 	return (0);
// }

int	exiter(void	*param)
{
	t_game *game;

	game = (t_game *)param;
	error_exit(NULL, game);
	return(0);
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_game	game;
			
	memset(&map, 0, sizeof(map));
	memset(&game, 0, sizeof(game));
	parssing(&map, argc, argv);
	//          print all information i got from parssing to ensure everything is good  //

	printf("%d\n", map.line_count);
	printf("%d\n", map.grid_lines_count);
	printf("%d\n", map.has_ceiling);
	printf("%d\n", map.has_floor);
	printf("%s\n", map.ea);
	printf("%s\n", map.no);
	printf("%s\n", map.so);
	printf("%s\n", map.we);
	printf("%d\n", map.floor_b);
	printf("%d\n", map.floor_g);
	printf("%d\n", map.floor_r);
	printf("%d\n", map.ceiling_b);
	printf("%d\n", map.ceiling_g);
	printf("%d\n", map.ceiling_r);
	printf("%d\n", map.map_width);
	printf("%c\n", map.player_dir);
	printf("%f\n", map.player_x);
	printf("%f\n", map.player_y);
	int i = 0;
	while (map.map_two_d[i])
	{
		printf("%s", map.map_two_d[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (map.map_grid[i])
	{
		printf("%s\n", map.map_grid[i]);
		i++;
	}

	// 				everything now is fine with parssing so let's go		//

	//the colors u asked me to parse :
	printf("============================\n");
	printf("%d\n",map.floor_color);
	printf("%d\n",map.ceiling_color);
	
	// game.map = &map;
	// game_init(&game);
	// rendering(&game);
	// mlx_hook(game.win, 17, 0, exiter, &game);
	// mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	// mlx_hook(game.win, 3, 1L << 1, key_release, &game);
	
	// // mlx_loop_hook(game.mlx, render_frame, &game);

	// mlx_loop(game.mlx);
	// ft_gc(0, 'f');
	return (0);
}
