/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_distance2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjbar <mbenjbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:46:15 by mbenjbar          #+#    #+#             */
/*   Updated: 2025/10/14 19:56:45 by mbenjbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void    final_distance(t_game *game)
{
    double  hori_dist;
    double  verti_dist;
    double  x_diff;
    double  y_diff;

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
