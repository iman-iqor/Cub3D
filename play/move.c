/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 21:26:57 by mbenjbar          #+#    #+#             */
/*   Updated: 2025/11/01 18:33:07 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	vertical(t_game *game, double *x, double *y)
{
	if (game->key_up == true)
	{
		*x += STEP * cos(game->angle);
		*y -= STEP * sin(game->angle);
	}
	if (game->key_down == true)
	{
		*x -= STEP * cos(game->angle);
		*y += STEP * sin(game->angle);
	}
}

void	horizontal(t_game *game, double *x, double *y)
{
	if (game->key_left == true)
	{
		*x -= STEP * sin(game->angle);
		*y -= STEP * cos(game->angle);
	}
	if (game->key_right == true)
	{
		*x += STEP * sin(game->angle);
		*y += STEP * cos(game->angle);
	}
}

void	rotation(t_game *game)
{
	if (game->rot_right == true)
		game->angle -= game->rot_angle;
	if (game->rot_left == true)
		game->angle += game->rot_angle;
}

int	render_frame(void *param)
{
	t_game	*game;
	double	x;
	double	y;
	double	angle;

	game = (t_game *)param;
	x = game->p_x;
	y = game->p_y;
	angle = game->angle;
	rotation(game);
	vertical(game, &x, &y);
	horizontal(game, &x, &y);
	if (game->p_x == x && game->p_y == y && angle == game->angle)
		return (0);
	if (!found(game, x, y))
	{
		game->p_x = x;
		game->p_y = y;
	}
	normalize(&game->angle);
	rendering(game);
	return (0);
}
