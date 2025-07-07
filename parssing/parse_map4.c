/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:24:50 by imiqor            #+#    #+#             */
/*   Updated: 2025/07/07 22:55:15 by imiqor           ###   ########.fr       */
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
/*
Is not on the border,

Is not touching a space ' ',

Is not near a row that is too short (avoids segmentation fault or undefined access).
*/
void	validate_walls(t_map *map)
{
	int	i;
	int	j;

	map->grid_lines_count = count_map_lines(map->map_grid, 0);
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
                    {
                        ftt_free(map->map_grid);
					error_exit("Error\nMap is not closed around");
                    }
			}
		}
	}
}
