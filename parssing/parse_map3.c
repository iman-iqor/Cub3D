/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjbar <mbenjbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:51:47 by imiqor            #+#    #+#             */
/*   Updated: 2025/10/10 22:48:39 by mbenjbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../header.h"

int is_valid_map_char(char c)
{
	if(c == '0' || c == '1' || c == ' ' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return 1;
    return (0);
}

void validate_map_chars(t_map *map)
{
	int player_count;
	char* line;
	int i;
	int j;

	j = 0;
	i = 0;
    player_count = 0;
    while(i < map->grid_lines_count)
    {
        line = map->map_grid[i];
		j = 0;
        while( line[j])
        {
            if (!is_valid_map_char(line[j]))
			{
                error_exit("Invalid character in map", NULL);
			}
            if (line[j] == 'N' || line[j] == 'S' || line[j] == 'E' || line[j] == 'W')
                player_count++;
			j++;
        }
		i++;
    }
    if (player_count != 1)
        error_exit("Map must have exactly one player start", NULL);
}
