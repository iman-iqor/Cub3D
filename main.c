/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:51:17 by imiqor            #+#    #+#             */
/*   Updated: 2025/07/09 21:50:09 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"






int	render_frame(t_game *game)
{
	// Redraw everything here
	draw_map_and_player(game, &game->map);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}
int	main(int argc, char **argv)
{
	t_map	map;
	t_game	game;

	parssing(&map, argc, argv);
	init_game(&game, &map);
	mlx_loop_hook(game.mlx, render_frame, &game);
	mlx_loop(game.mlx);
	// load_images(&game,&map);
	mlx_loop(game.mlx);
	ft_gc(0, 'f');
	return (0);
}
