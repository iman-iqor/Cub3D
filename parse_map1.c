/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:51:32 by imiqor            #+#    #+#             */
/*   Updated: 2025/07/03 00:51:33 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include"header.h"






void validate_walls(t_map *map)
{
	int i  = 0;
	int j = 0;
	map->grid_lines_count=count_map_lines(map->map_grid,0);
	while(map->map_grid[i])
	{
		j = 0;
		// printf("\n%d|}}\n", ft_strlen(map->map_grid[i]));
		while(map->map_grid[i][j])
		{
			// if((map->map_grid[i][j] == '0') && ((map->map_grid[i][j-1] != '1') || (map->map_grid[i][j+1] != '1') ||( map->map_grid[i+1][j] != '1') || (map->map_grid[i-1][j] != '1') ))
			// {
			// 	printf("|%c|",map->map_grid[1][j]);
			// 	write(2,"void not sorrounded\n",21);
			// 	exit(1);
			// }
			j++;
		}
		i++;
	}
}


void parse_map(t_map *map, char **content, int start)
{
    store_map_lines(content, start, map);
    validate_map_chars(map);
	validate_walls(map);
    // validate_map_borders(map);
    // find player pos and store
}