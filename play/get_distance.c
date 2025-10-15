/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjbar <mbenjbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 10:15:05 by mbenjbar          #+#    #+#             */
/*   Updated: 2025/10/14 21:01:37 by mbenjbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int found(t_game *game, double x, double y)
{
    int	player_x;
	int	player_y;

	player_x = x / TILE_SIZE;
	player_y = y / TILE_SIZE;
	if (player_y < 0 || player_y >= game->map_height)
		return (1);
	if (player_x < 0 || player_x >= game->map_width)
		return (1);
	if (game->grid[player_y][player_x] == '1')
		return (1);
	return (0);
}

void    find_wall(t_game *game)
{
    while (1 && game->cur_angle != M_PI && game->cur_angle != 0)
    {
        if (found(game, game->dist->h_hitx, game->dist->h_hity))
            break;
        game->dist->h_hitx += game->dist->xh_step;
        game->dist->h_hity += game->dist->yh_step;
    }
    while (1 && game->cur_angle != 0.5 * M_PI && game->cur_angle != 1.5 * M_PI)
    {
        if (found(game, game->dist->v_hitx, game->dist->v_hity))
            break;
        game->dist->v_hitx += game->dist->xv_step;
        game->dist->v_hity += game->dist->yv_step;
    }
    
}

void    hori_first_inter(t_game *game)
{
    game->dist->h_hity = floor(game->p_y / TILE_SIZE) * TILE_SIZE;
    game->dist->h_hity += TILE_SIZE * down(game->cur_angle);
    game->dist->h_hitx = game->p_x +
        (game->dist->h_hity - game->p_y) / tan(game->cur_angle);
    game->dist->yh_step = TILE_SIZE;
    game->dist->xh_step = fabs(TILE_SIZE / tan(game->cur_angle));
    if (up(game->cur_angle))
        game->dist->yh_step *= -1;
    if (left(game->cur_angle))
        game->dist->xh_step *= -1;
    game->dist->h_hity -= up(game->cur_angle);
}

void    verti_first_inter(t_game *game)
{
    game->dist->v_hitx = floor(game->p_x / TILE_SIZE) * TILE_SIZE;
    game->dist->v_hitx += TILE_SIZE * right(game->cur_angle);
    game->dist->v_hity = game->p_x +
        (game->dist->v_hitx - game->p_x) * tan(game->cur_angle);
    game->dist->xv_step = TILE_SIZE;
    game->dist->yv_step = fabs(TILE_SIZE * tan(game->cur_angle));
    if (left(game->cur_angle))
        game->dist->xv_step *= -1;
    if (up(game->cur_angle))
        game->dist->yv_step *= -1;
    game->dist->v_hitx -= left(game->cur_angle);
}

void  get_dist(t_game *game)
{
    if (game->cur_angle == M_PI || game->cur_angle == 0)
    {
        verti_first_inter(game);
        game->dist->h_hitx = game->p_x;
        game->dist->h_hity = game->p_y;
    }
    else if (game->cur_angle != 0.5 * M_PI || game->cur_angle != 1.5 * M_PI)
    {
        hori_first_inter(game);
        game->dist->v_hitx = game->p_x;
        game->dist->v_hitx = game->p_y;
    }
    else
    {
        verti_first_inter(game);
        hori_first_inter(game);
    }
    find_wall(game);
    final_distance(game);
}
