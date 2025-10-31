/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 10:15:05 by mbenjbar          #+#    #+#             */
/*   Updated: 2025/10/31 21:48:20 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	found(t_game *game, int x, int y)
{
	int	player_x;
	int	player_y;

	player_x = x / TILE_SIZE;
	player_y = y / TILE_SIZE;
	if (player_y < 0 || player_y >= game->map_height)
		return (1);
	if (player_x < 0 || player_x >= (int)ft_strlen(game->grid[player_y]))
		return (1);
	if (game->grid[player_y][player_x] == '1')
		return (1);
	return (0);
}

void	find_wall(t_game *game)
{
	while (1)
	{
		if (found(game, game->dist->h_hitx, game->dist->h_hity) == 1)
			break ;
		game->dist->h_hitx += game->dist->xh_step;
		game->dist->h_hity += game->dist->yh_step;
	}
	while (1)
	{
		if (found(game, game->dist->v_hitx, game->dist->v_hity) == 1)
			break ;
		game->dist->v_hitx += game->dist->xv_step;
		game->dist->v_hity += game->dist->yv_step;
	}
}

void	hori_first_inter(t_game *game)
{
	game->dist->h_hity = floor(game->p_y / TILE_SIZE) * TILE_SIZE;
	if (down(game->cur_angle))
		game->dist->h_hity += TILE_SIZE;
	game->dist->h_hitx = game->p_x - ((game->dist->h_hity - game->p_y)
			/ tan(game->cur_angle));
	game->dist->yh_step = TILE_SIZE;
	game->dist->xh_step = TILE_SIZE / tan(game->cur_angle);
	if (up(game->cur_angle))
		game->dist->yh_step = -game->dist->yh_step;
	if (left(game->cur_angle))
		game->dist->xh_step = -fabs(game->dist->xh_step);
	else
		game->dist->xh_step = fabs(game->dist->xh_step);
	if (up(game->cur_angle))
		game->dist->h_hity--;
}

void	verti_first_inter(t_game *game)
{
	game->dist->v_hitx = floor(game->p_x / TILE_SIZE) * TILE_SIZE;
	if (right(game->cur_angle))
		game->dist->v_hitx += TILE_SIZE;
	game->dist->v_hity = game->p_y - ((game->dist->v_hitx - game->p_x)
			* tan(game->cur_angle));
	game->dist->xv_step = TILE_SIZE;
	game->dist->yv_step = TILE_SIZE * tan(game->cur_angle);
	if (left(game->cur_angle))
		game->dist->xv_step = -game->dist->xv_step;
	if (up(game->cur_angle))
		game->dist->yv_step = -fabs(game->dist->yv_step);
	else
		game->dist->yv_step = fabs(game->dist->yv_step);
	if (left(game->cur_angle))
		game->dist->v_hitx--;
}

void	final_distance(t_game *game)
{
	double	hori_dist;
	double	verti_dist;
	double	x_diff;
	double	y_diff;

	x_diff = game->dist->h_hitx - game->p_x;
	y_diff = game->dist->h_hity - game->p_y;
	hori_dist = sqrt((x_diff * x_diff) + (y_diff * y_diff));
	x_diff = game->dist->v_hitx - game->p_x;
	y_diff = game->dist->v_hity - game->p_y;
	verti_dist = sqrt((x_diff * x_diff) + (y_diff * y_diff));
	if (verti_dist < hori_dist)
		game->wall_distance = verti_dist;
	else
		game->wall_distance = hori_dist;
	game->flag = (hori_dist < verti_dist);
}
