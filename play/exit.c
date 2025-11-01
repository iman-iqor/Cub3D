/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 21:33:23 by mbenjbar          #+#    #+#             */
/*   Updated: 2025/11/01 18:32:37 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	destroy_text(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->textures[i].textu)
			mlx_destroy_image(game->mlx, game->textures[i].textu);
		i++;
	}
}

void	error_exit(char *msg, t_game *game)
{
	if (msg)
	{
		write(2, "Error ", 7);
		write(2, msg, ft_strlen(msg));
		write(2, "\n", 1);
	}
	if (game)
	{
		if (game->mlx)
		{
			if (game->img)
				mlx_destroy_image(game->mlx, game->img);
			destroy_text(game);
			if (game->win)
				mlx_destroy_window(game->mlx, game->win);
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
	}
	ft_gc(0, 'f');
	exit(1);
}
