/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:40:33 by imiqor            #+#    #+#             */
/*   Updated: 2025/09/22 22:32:25 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"header.h"

void	put_pixel(t_game *g, int x, int y, int color)
{
	char	*dst;
	// 1) calculate the address of pixel (x,y):
	dst = g->data_addr + y * g->line_len // jump down y rows
		+ x * (g->bpp / 8);              // jump right x pixels
	// 2) write your 32‑bit color into that spot:
	*(unsigned int *)dst = color; // color is 0xRRGGBB
}
void	draw_player(t_game *game, t_map *map)
{
	int	px;
	int	py;
	int	dy;
	int	dx;

	px = map->player_x * TILE_SIZE;
	py = map->player_y * TILE_SIZE;
	put_pixel(game, px, py+1, 0xFF0000);
	put_pixel(game, px+1, py+1, 0xFF0000);
	put_pixel(game, px+1, py, 0xFF0000);
	put_pixel(game, px, py, 0xFF0000);

	int size = TILE_SIZE ;
}

void	draw_tile(t_game *g, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			put_pixel(g, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_map_and_player(t_game *game, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_grid[i])
	{
		j = 0;
		while (map->map_grid[i][j])
		{
			if (map->map_grid[i][j] == '1')
				draw_tile(game, j * TILE_SIZE, i * TILE_SIZE, 0x0000FF);
			else
				draw_tile(game, j * TILE_SIZE, i * TILE_SIZE, 0xFFFF00);
			j++;
		}
		i++;
	}
	draw_player(game, map);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}
