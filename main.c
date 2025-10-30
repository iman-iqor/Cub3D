/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjbar <mbenjbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:51:17 by imiqor            #+#    #+#             */
/*   Updated: 2025/10/18 22:03:26 by mbenjbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
	game.map = &map;
	game_init(&game);
	rendering(&game);
	mlx_hook(game.win, 17, 0, exiter, &game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, key_release, &game);
	mlx_loop_hook(game.mlx, render_frame, &game);
	mlx_loop(game.mlx);
	ft_gc(0, 'f');
	return (0);
}
