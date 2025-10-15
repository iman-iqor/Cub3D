/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjbar <mbenjbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:51:40 by imiqor            #+#    #+#             */
/*   Updated: 2025/10/10 22:48:26 by mbenjbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../header.h"
int count_map_lines(char **content, int start)
{
    int count;

    count = 0;
    while (content[start + count])
        count++;
    return count;
}

void trim_newline(char *str)
{
    int len = ft_strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';
}

void store_map_lines(char **content, int start, t_map *map)
{
	int map_lines;
	int j;
	j = 0;
    map->grid_lines_count = count_map_lines(content, start);
    map->map_grid = ft_gc(sizeof(char *) * (map->grid_lines_count + 1),'m');
    if (!map->map_grid)
	{
        error_exit("Malloc failed for map grid", NULL);
	}
    while (j < map->grid_lines_count)
	{
        map->map_grid[j] = ftt_strdup(content[start + j]);
		trim_newline(map->map_grid[j]); 
		j++;
		
	}
    map->map_grid[map->grid_lines_count] = NULL;
}
