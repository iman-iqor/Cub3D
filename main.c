/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:51:17 by imiqor            #+#    #+#             */
/*   Updated: 2025/07/03 00:51:18 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "header.h"



void	check_map_content(char **content, t_map *map)
{
	int	i;

	i = 0;
	parse_textures_and_colors(map->map_two_d, &i, map);
	while (content[i] && ft_strcmp(content[i], "\n") == 0)
		i++;
	if (!content[i])
		write(2, "Map doesn't exist!\n", 20);
	check_no_blank_lines_inside_map(content, i);
	parse_map(map,content,i);
}

int	main(int argc, char **argv)
{
	t_map	map;

	ft_memset(&map, 0, sizeof(t_map));
	check_argc(argc);
	check_extention(argv[1]);
	check_if_file_exist(argv[1]);
	get_cub_content(argv[1], &map);
	check_map_content(map.map_two_d, &map);
	return (0);
}
