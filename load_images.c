/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:47:44 by imiqor            #+#    #+#             */
/*   Updated: 2025/07/09 21:48:47 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"header.h"


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