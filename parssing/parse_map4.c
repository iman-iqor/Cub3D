/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjbar <mbenjbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:24:50 by imiqor            #+#    #+#             */
/*   Updated: 2025/10/10 22:26:12 by mbenjbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_check_is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}
int is_not_sorrounded(t_map *map,int i,int j)
{
    if(i == 0 || j == 0)
        return 1;
    if(i == map->grid_lines_count - 1)
        return 1;
    if(j == ft_strlen(map->map_grid[i]) - 1)
        return 1;
    if(!map->map_grid[i][j + 1])
        return 1;
    if( map->map_grid[i][j + 1] == ' ' )
        return 1;
    if(map->map_grid[i][j - 1] == ' ')
        return 1;
    if( !map->map_grid[i + 1][j])
        return 1;
    if(map->map_grid[i + 1][j] == ' ')
        return 1;
    if(map->map_grid[i - 1][j] == ' ')
        return 1;
    if(ft_strlen(map->map_grid[i + 1]) < j + 1)
        return 1;
    if(ft_strlen(map->map_grid[i - 1]) < j + 1)
        return 1;
    return 0;
}

void	validate_walls(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map_grid[++i])
	{
		j = -1;
		while (map->map_grid[i][++j])
		{
			if (map->map_grid[i][j] == '0'
				|| ft_check_is_player(map->map_grid[i][j]))
			{
				if (is_not_sorrounded(map, i ,j))
					    error_exit("Map is not closed around", NULL);
			}
		}
	}
}
