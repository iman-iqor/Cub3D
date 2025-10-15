// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   draw_map.c                                         :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/07/09 21:40:33 by imiqor            #+#    #+#             */
// /*   Updated: 2025/09/23 17:34:36 by imiqor           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include"header.h"

// void	put_pixel(t_game *g, int x, int y, int color)
// {
// 	if(x>= g->win_width || y >= g->win_height || x< 0 || y < 0)
// 		return ;
// 	int index = y * g->line_len  + x * (g->bpp / 8); 
// 	g->data_addr[index]=color&0xFF; 
// 	g->data_addr[index+1]=(color>>8)&0xFF; 
// 	g->data_addr[index+2]=(color>>16 )&0xFF;
	

// }
// void draw_line_len(t_game *game, int x0, int y0, float angle, int len, int color);
// void	draw_player(t_game *game, t_map *map)
// {
// 	int	px;
// 	int	py;
// 	int	dy;
// 	int	dx;

// 	px = map->player_x * TILE_SIZE;
// 	py = map->player_y * TILE_SIZE;

// 	dy = -3;
// 	while (dy <= 3)
// 	{
// 		dx = -3;
// 		while (dx <= 3)
// 		{
// 			put_pixel(game, px + dx, py + dy, 0xFF0000);
// 			dx++;
// 		}
// 		dy++;
// 	}

// 	// int max_len = (game->win_width > game->win_height) ? game->win_width : game->win_height;
//     // optionally multiply by 2 for long rays: max_len *= 2;

//     draw_line_len(game, px, py, game->angle, 2000, 0xF0000F);
// }


// void	draw_tile(t_game *g, int x, int y, int color)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < TILE_SIZE)
// 	{
// 		j = 0;
// 		while (j < TILE_SIZE)
// 		{
// 			put_pixel(g, x + j, y + i, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }
// // include whatever header has t_game, touch(), TILE_SIZE, put_pixel, etc.
// #include "header.h"
// #include <math.h>
// bool touch(float px, float py, t_game *game);
// // Bresenham-based line that stops when it hits a wall (touch)
// void draw_line_len(t_game *game, int x0, int y0, float angle, int len, int color)
// {
//     int x1 = x0 - (int)roundf(cosf(angle) * (float)len);
//     int y1 = y0 - (int)roundf(sinf(angle) * (float)len);

//     int dx = abs(x1 - x0);
//     int sx = x0 < x1 ? 1 : -1;
//     int dy = -abs(y1 - y0);
//     int sy = y0 < y1 ? 1 : -1;
//     int err = dx + dy;

//     while (1)
//     {
//         // draw pixel
//         put_pixel(game, x0, y0, color);

//         // stop if we hit a wall at this pixel
//         if (touch((float)x0, (float)y0, game))
//             return;

//         // finished
//         if (x0 == x1 && y0 == y1)
//             break;

//         int e2 = 2 * err;
//         if (e2 >= dy)
//         {
//             err += dy;
//             x0 += sx;
//         }
//         if (e2 <= dx)
//         {
//             err += dx;
//             y0 += sy;
//         }
//     }
// }


// void	draw_map_and_player(t_game *game, t_map *map)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (map->map_grid[i])
// 	{
// 		j = 0;
// 		while (map->map_grid[i][j])
// 		{
// 			if (map->map_grid[i][j] == '1')
// 				draw_tile(game, j * TILE_SIZE, i * TILE_SIZE, 0x0000FF);
// 			else
// 				draw_tile(game, j * TILE_SIZE, i * TILE_SIZE, 0xFFFF00);
// 			j++;
// 		}
// 		i++;
// 	}
// 	draw_player(game, map);
// 	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
// }
