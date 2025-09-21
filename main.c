/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:51:17 by imiqor            #+#    #+#             */
/*   Updated: 2025/09/21 18:52:49 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_free_image(t_game *game)
{
	if (!game)
        return;
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		//free(game->mlx);
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
	if(game->rot_left)
	{
		game->map.player_x = game->map.player_x -50;
		// game->map.player_y =game->map.player_y +0.1 ;
		mlx_clear_window(game->mlx,game->win);
		// printf("%d\n",game->map.player_y);
	}
	// Redraw everything here
	draw_map_and_player(game, &game->map);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}


int exiter(int key)
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
	mlx_loop_hook(game.mlx, render_frame, &game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 17, 0,exiter, &game);
	mlx_hook(game.win, 3, 1L << 1, key_release, &game);
	mlx_loop(game.mlx);
	ft_gc(0, 'f');
	return (0);
}
