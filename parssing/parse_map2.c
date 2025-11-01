/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:51:40 by imiqor            #+#    #+#             */
/*   Updated: 2025/11/01 18:54:20 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	count_map_lines(char **content, int start)
{
	int	count;

	count = 0;
	while (content[start + count])
		count++;
	return (count);
}

// Map parsing or validation functions might 
//read the newline as an actual character.
// For example, when checking walls
// ('1', '0', 'N', 'E', etc.),
// the newline '\n' could
// appear as an unexpected character at the end of a row.
void	trim_newline(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
		str[len - 1] = '\0';
}

void	store_map_lines(char **content, int start, t_map *map)
{
	int	j;

	j = 0;
	map->grid_lines_count = count_map_lines(content, start);
	map->map_grid = ft_gc(sizeof(char *) * (map->grid_lines_count + 1), 'm');
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
