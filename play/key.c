/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjbar <mbenjbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 08:58:38 by mbenjbar          #+#    #+#             */
/*   Updated: 2025/10/11 09:02:40 by mbenjbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	key_press(int key, void *param)
{
    t_game  *game;

    game = (t_game *)param;
	if (key == ESC_KEY)
		error_exit(NULL, game);
	else if (key == W)
		game->key_up = true;
	else if (key == S)
		game->key_down = true;
	else if (key == A)
		game->key_left = true;
	else if (key == D)
		game->key_right = true;
	else if (key == LEFT_ARROW)
		game->rot_left = true;
	else if (key == RIGHT_ARROW)
		game->rot_right = true;
	return (0);
}

int	key_release(int key, void *param)
{
    t_game  *game;

    game = (t_game *)param;
	if (key == W)
		game->key_up = false;
	else if (key == S)
		game->key_down = false;
	else if (key == A)
		game->key_left = false;
	else if (key == D)
		game->key_right = false;
	else if (key == LEFT_ARROW)
		game->rot_left = false;
	else if (key == RIGHT_ARROW)
		game->rot_right = false;
	return (0);
}
