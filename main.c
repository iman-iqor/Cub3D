/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:51:17 by imiqor            #+#    #+#             */
/*   Updated: 2025/09/22 22:32:56 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_free_image(t_game *game)
{
	if (!game)
		return ;
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		// free(game->mlx);
	}
	ft_gc(0, 'f');
	exit(0);
}

// In input.c
int	key_press(int key, t_game *g)
{
	if (key == ESC_KEY)
		ft_free_image(g);
	else if (key == W)
		g->key_up = true;
	else if (key == S)
		g->key_down = true;
	else if (key == A)
		g->key_left = true;
	else if (key == D)
		g->key_right = true;
	else if (key == LEFT_ARROW)
		g->rot_left = true;
	else if (key == RIGHT_ARROW)
		g->rot_right = true;
	return (0);
}

int	key_release(int key, t_game *g)
{
	if (key == W)
		g->key_up = false;
	else if (key == S)
		g->key_down = false;
	else if (key == A)
		g->key_left = false;
	else if (key == D)
		g->key_right = false;
	else if (key == LEFT_ARROW)
		g->rot_left = false;
	else if (key == RIGHT_ARROW)
		g->rot_right = false;
	return (0);
}

int	render_frame(t_game *game)
{
	float	x;

	if (game->key_left)
	{
		x = game->map.player_x - 0.01;
		if (game->map.map_grid[(int)game->map.player_y][(int)x] == '0')
			game->map.player_x = x;
		mlx_clear_window(game->mlx, game->win);
	}
	if (game->key_right)
	{
		x = game->map.player_x + 0.01 ; 
		if (game->map.map_grid[(int)game->map.player_y][(int)x] == '0')
		game->map.player_x = x;
		mlx_clear_window(game->mlx, game->win);
	}
	if (game->key_up)
	{
		printf("up\n");
		x = game->map.player_y - 0.01;
		if (game->map.map_grid[(int)x][(int)game->map.player_x] == '0')
			game->map.player_y = x;
		mlx_clear_window(game->mlx, game->win);
	}
	if (game->key_down)
	{
		x = game->map.player_y + 0.01;
		if (game->map.map_grid[(int)x ][(int)game->map.player_x] == '0')
		game->map.player_y = x;
		mlx_clear_window(game->mlx, game->win);
	}
	draw_map_and_player(game, &game->map);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}

int	exiter(int key)
{
	exit(key);
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_game	game;

	memset(&map, 0, sizeof(map));
	memset(&game, 0, sizeof(game));
	parssing(&map, &game, argc, argv);
	init_game(&game, &map);
	game.map.map_grid[(int)game.map.player_y][(int)game.map.player_x] = '0';
	mlx_loop_hook(game.mlx, render_frame, &game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 17, 0, exiter, &game);
	mlx_hook(game.win, 3, 1L << 1, key_release, &game);
	mlx_loop(game.mlx);
	ft_gc(0, 'f');
	return (0);
}
