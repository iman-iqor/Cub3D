/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:51:03 by imiqor            #+#    #+#             */
/*   Updated: 2025/07/09 23:12:59 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include"../header.h"
void parssing(t_map* map,t_game* game, int argc,char** argv)
{
	ft_memset(map, 0, sizeof(t_map));
	ft_memset(game, 0, sizeof(t_game));
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
		write(2, "Map doesn't exist!\n", 20);
	check_no_blank_lines_inside_map(content, i);
	parse_map(map,content,i);
}

int	check_if_file_exist(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		perror("Error\n");
		exit(1);
	}
	close(fd);
	return (fd);
}
void	check_extention(char *argv)
{
	int		len;
	char	*tmp;

	len = ft_strlen(argv);
	tmp = ft_strrchr(argv, '/');
	if ((ft_strncmp(argv + len - 4, ".cub", 4)) || (ft_strlen(argv) <= 4)
		|| (tmp && ft_strlen(ft_strrchr(tmp, '/')) <= 5))
	{
		write(1, "Error \n bad extension\n", 23);
		exit(1);
	}
}
void	check_argc(int argc)
{
	if (argc != 2)
	{
		write(1, "Usage: ./cub3D ./path_to_map\n", 30);
		exit(1);
	}
}
