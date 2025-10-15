/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjbar <mbenjbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:06:11 by mbenjbar          #+#    #+#             */
/*   Updated: 2025/10/15 10:23:43 by mbenjbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void    put_pix(t_game *game, int i, unsigned int color)
{

}

void    draw(t_game *game)
{
    int             start;
    int             end;
    int             i;
    unsigned int    color;
    
    start = (WINDOW_HEIGHT / 2) - (game->height_wall / 2);
    end = start + game->height_wall;
    i = 0;
    while (i < WINDOW_HEIGHT)
    {
        if (i >= start && i <= end)
            draw_wall();
        else if (i < start)
            put_pix();
        else
            draw_floor();
        i++;
    }
}
