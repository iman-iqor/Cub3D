/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjbar <mbenjbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:06:11 by mbenjbar          #+#    #+#             */
/*   Updated: 2025/10/28 14:57:54 by mbenjbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void get_index(t_game *game)
{
    if (game->flag)
    {
        if (up(game->cur_angle))
            game->text_index = 3;
        else
            game->text_index = 1;
    }
    else
    {
        if (right(game->cur_angle))
            game->text_index = 0;
        else
            game->text_index = 2;
    }
}

void get_column(t_game *game)
{
    int index;

    get_index(game);
    index = game->text_index;
    if (game->flag)
		game->text_column = (int)game->dist->h_hitx % TILE_SIZE
			* (game->textures[index].width / TILE_SIZE);
	if (!game->flag)
		game->text_column = (int)game->dist->v_hity % TILE_SIZE
			* (game->textures[index].width / TILE_SIZE);
}

unsigned int get_color(t_game *game, int row)
{
	char	*color;
    int     index;

    index = game->text_index;
	if (game->text_column < 0 || 
        game->text_column > game->textures[index].width || row < 0
        || row > game->textures[index].height)
		return (0);
	color = game->textures[index].address
        + (row * game->textures[index].lenght) + game->text_column
		* (game->textures[index].bpp / 8);
	return (*(unsigned int *)color);
}

void    put_pix(t_game *game, int i, unsigned int color)
{
    char *address;

    address = game->data_addr + (i * game->line_len) + (game->cur_column * (game->bpp / 8));
    *(unsigned int *)address = color;
}

void    draw(t_game *game)
{
    int             start;
    int             end;
    int             i;
    int             row;
    
    start = (WINDOW_HEIGHT / 2) - (game->height_wall / 2);
    end = start + game->height_wall;
    i = 0;
    while (i < WINDOW_HEIGHT)
    {
        if (i >= start && i <= end)
        {
            get_column(game);
            row = (i - start) * (game->textures[game->text_index].height
					/ game->height_wall);
            put_pix(game, i, get_color(game, row));
        }
        else if (i < start)
            put_pix(game, i, game->map->ceiling_color);
        else
            put_pix(game, i, game->map->floor_color);
        i++;
    }
}

