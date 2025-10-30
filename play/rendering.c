/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjbar <mbenjbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 09:09:33 by mbenjbar          #+#    #+#             */
/*   Updated: 2025/10/28 15:29:40 by mbenjbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void    normalize(double *angle)
{
    if (angle)
    {
        (*angle) = fmod(*angle, 2 * M_PI);
	    if ((*angle) < 0)
		    (*angle) += 2 * M_PI;
    }
}

void    draw_angle(t_game *game)
{
    double  projection_dis;

    verti_first_inter(game);
    hori_first_inter(game);
    find_wall(game);
    final_distance(game);
    projection_dis = (WINDOW_WIDTH / 2) / tan(game->fov / 2);
    game->wall_distance = game->wall_distance * cos(game->cur_angle - game->angle);
    game->height_wall = (TILE_SIZE / game->wall_distance) * projection_dis;
    draw(game);
}

void    rendering(t_game *game)
{
    double  angle_diff;

    if(game->img)
        mlx_destroy_image(game->mlx, game->img);
    game->img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
    if (game->img == NULL)
        error_exit("failed to get new image", game);
    game->data_addr = mlx_get_data_addr(game->img, &game->bpp,
        &game->line_len, &game->endian);
    game->cur_column = 0;
    game->cur_angle = game->angle + (game->fov / 2);
    angle_diff = game->fov / WINDOW_WIDTH;
    while (game->cur_column < WINDOW_WIDTH)
    {
        normalize(&game->cur_angle);
        draw_angle(game);
        game->cur_angle -= angle_diff;
        game->cur_column++;
    }
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}
