/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:51:03 by imiqor            #+#    #+#             */
/*   Updated: 2025/11/01 18:53:51 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	parssing(t_map *map, int argc, char **argv)
{
	check_argc(argc);
	check_extention(argv[1]);
	check_if_file_exist(argv[1]);
	get_cub_content(argv[1], map);
	check_map_content(map->map_two_d, map);
}

void	check_map_content(char **content, t_map *map)
{
	int	i;

	i = 0;
	parse_textures_and_colors(map->map_two_d, &i, map);
	while (content[i] && ft_strcmp(content[i], "\n") == 0)
		i++;
	if (!content[i])
		error_exit("Map doesn't exist!\n", NULL);
	map->start_of_map = i + 1;
	check_no_blank_lines_inside_map(content, i);
	parse_map(map, content, i);
}

void	check_if_file_exist(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		error_exit("file does not exist", NULL);
	close(fd);
	return ;
}

void	check_extention(char *argv)
{
	int		len;

	len = ft_strlen(argv);
	if ((ft_strncmp(argv + len - 4, ".cub", 4)) || (ft_strlen(argv) <= 4))
	{
		error_exit("bad extension", NULL);
	}
}

void	check_argc(int argc)
{
	if (argc != 2)
		error_exit("Usage: ./cub3D ./path_to_map", NULL);
}
