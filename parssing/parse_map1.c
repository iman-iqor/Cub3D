/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjbar <mbenjbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:51:32 by imiqor            #+#    #+#             */
/*   Updated: 2025/10/09 21:43:08 by mbenjbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	find_player_position(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->map_width = 0;
	while (map->map_grid[i])
	{
		if (ft_strlen(map->map_grid[i]) > map->map_width)
			map->map_width = ft_strlen(map->map_grid[i]);

		j = 0;
		while (map->map_grid[i][j])
		{
			if (ft_check_is_player(map->map_grid[i][j]))
			{
				map->player_x = j;
				map->player_y = i;
				map->player_dir = map->map_grid[i][j];
			}
			j++;
		}
		i++;
	}
}

void	parse_map(t_map *map, char **content, int start)
{
	store_map_lines(content, start, map);
	validate_map_chars(map);
	validate_walls(map);
	find_player_position(map);
}
