/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:40:33 by imiqor            #+#    #+#             */
/*   Updated: 2025/09/23 17:34:36 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"header.h"

void	put_pixel(t_game *g, int x, int y, int color)
{
	if(x>= g->win_width || y >= g->win_height || x< 0 || y < 0)
		return ;
	int index = y * g->line_len  + x * (g->bpp / 8); 
	g->data_addr[index]=color&0xFF; 
	g->data_addr[index+1]=(color>>8)&0xFF; 
	g->data_addr[index+2]=(color>>16 )&0xFF;
	

}
void	draw_player(t_game *game, t_map *map)
{
	int	px;
	int	py;
	int	dy;
	int	dx;

	px = map->player_x * TILE_SIZE;
	py = map->player_y * TILE_SIZE;

	dy = -1;
	while (dy <= 1)
	{
		dx = -1;
		while (dx <= 1)
		{
			put_pixel(game, px + dx, py + dy, 0xFF0000);
			dx++;
		}
		dy++;
	}

	int size = TILE_SIZE;
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
