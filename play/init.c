/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjbar <mbenjbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 20:35:01 by mbenjbar          #+#    #+#             */
/*   Updated: 2025/10/28 15:29:12 by mbenjbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void    texture_addr_loading(t_game *game)
{
    int i;

    game->textures[0].textu = mlx_xpm_file_to_image(game->mlx, game->map->ea,
            &game->textures[0].width, &game->textures[0].height);
    game->textures[1].textu = mlx_xpm_file_to_image(game->mlx, game->map->so,
            &game->textures[1].width, &game->textures[1].height);
    game->textures[2].textu = mlx_xpm_file_to_image(game->mlx, game->map->we,
            &game->textures[2].width, &game->textures[2].height);
    game->textures[3].textu = mlx_xpm_file_to_image(game->mlx, game->map->no,
            &game->textures[3].width, &game->textures[3].height);
    if (!game->textures[0].textu || !game->textures[1].textu
      || !game->textures[2].textu || !game->textures[3].textu)
    {
          error_exit("loading texture failure", game);
    }
    i = 0;
    while (i < 4)
    {
        game->textures[i].address = mlx_get_data_addr(game->textures[i].textu,
            &game->textures[i].bpp, &game->textures[i].lenght,
            &game->textures[i].endian);
        i++;
    }
}

static double  handle_direction(char direct)
{
	if (direct == 'N')
		return (90 * (M_PI / 180));
	if (direct == 'S')
		return (270 * (M_PI / 180));
	if (direct == 'E')
		return (0);
	else
		return (180 * (M_PI / 180));
}

void    game_init(t_game *game)
{
    game->fov = 60 * (M_PI / 180);
    game->rot_angle = 0.8 * (M_PI / 180);
    game->p_x = game->map->player_x * TILE_SIZE;
    game->p_y = game->map->player_y * TILE_SIZE;
    game->grid = game->map->map_grid;
    game->map_height = game->map->grid_lines_count;
    game->map_width = game->map->map_width;
    game->angle = handle_direction(game->map->player_dir);
    game->dist = ft_gc(sizeof(t_distance), 'm');
    game->mlx = mlx_init();
    texture_addr_loading(game);
    game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
}