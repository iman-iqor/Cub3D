/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:51:24 by imiqor            #+#    #+#             */
/*   Updated: 2025/10/30 16:11:03 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

/**
 * Counts the number of lines in the file specified by filename.
 * param filename The path to the file whose lines are to be counted.
 * return The number of lines in the file.
 */
int	nbr_of_lines(char *filename)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd, 0);
	while (line)
	{
		i++;
		line = get_next_line(fd, 0);
	}
	close(fd);
	return (i);
}

void	get_cub_content(char *argv, t_map *map)
{
	int	fd;
	int	i;

	i = 0;
	map->line_count = nbr_of_lines(argv);
	map->map_two_d = ft_gc(sizeof(char *) * (map->line_count + 1), 'm');
	if (!map->map_two_d)
		error_exit("Malloc Error", NULL);
	fd = open(argv, O_RDONLY);
	map->map_two_d[i] = get_next_line(fd, 0);
	while (i < map->line_count && map->map_two_d[i++])
	{
		map->map_two_d[i] = get_next_line(fd, 0);
	}
	map->map_two_d[i] = 0;
	close(fd);
}
