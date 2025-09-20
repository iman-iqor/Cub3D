/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:51:24 by imiqor            #+#    #+#             */
/*   Updated: 2025/09/20 18:17:00 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	nbr_of_lines(char *filename)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror(filename);
		ft_gc(0, 'f');
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd, 0);
	while (line)
	{
		// free(line);
		i++;
		line = get_next_line(fd, 0);
	}
	close(fd);
	return (i);
}
void	get_cub_content(char *argv, t_map *map)
{
	int	len;
	int	fd;
	int	i;

	i = 0;
	len = nbr_of_lines(argv);
	printf("%s\n", argv);
	map->line_count = len;
	map->map_two_d = ft_gc(sizeof(char *) * (len + 1), 'm');
	if (!map->map_two_d)
	{
		write(2, "Malloc Error: map_cotent.c: 52\n", 32);
		ft_gc(0, 'f');
		exit(1);
	}
	fd = open(argv, O_RDONLY);
	map->map_two_d[i] = get_next_line(fd, 0);
	while (i < len && map->map_two_d[i++])
	{
		map->map_two_d[i] = get_next_line(fd, 0);
	}
	map->map_two_d[i] = 0;
	close(fd);
}
