/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:51:59 by imiqor            #+#    #+#             */
/*   Updated: 2025/10/31 18:46:30 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	assign_texture(t_map *map, char *line, char **dest, char *id)
{
	char	*path;

	if (ft_strcmp(id, "NO") == 0 && map->has_no)
		error_exit("Duplicate NO texture", NULL);
	else if (ft_strcmp(id, "SO") == 0 && map->has_so)
		error_exit("Duplicate SO texture", NULL);
	else if (ft_strcmp(id, "WE") == 0 && map->has_we)
		error_exit("Duplicate WE texture", NULL);
	else if (ft_strcmp(id, "EA") == 0 && map->has_ea)
		error_exit("Duplicate EA texture", NULL);
	path = line + ft_strlen(id);
	while (*path == ' ')
		path++;
	*dest = trim_spaces_end(path);
	check_path(*dest);
}

void	parse_texture_line(char **lines, int *i, t_map *map)
{
	if (ft_strncmp(lines[*i], "NO ", 3) == 0)
	{
		assign_texture(map, lines[*i], &map->no, "NO");
		map->has_no = 1;
	}
	else if (ft_strncmp(lines[*i], "SO ", 3) == 0)
	{
		assign_texture(map, lines[*i], &map->so, "SO");
		map->has_so = 1;
	}
	else if (ft_strncmp(lines[*i], "WE ", 3) == 0)
	{
		assign_texture(map, lines[*i], &map->we, "WE");
		map->has_we = 1;
	}
	else if (ft_strncmp(lines[*i], "EA ", 3) == 0)
	{
		assign_texture(map, lines[*i], &map->ea, "EA");
		map->has_ea = 1;
	}
	(*i)++;
}

void	parse_color_line(char **lines, int *i, t_map *map)
{
	if (ft_strncmp(lines[*i], "F ", 2) == 0)
	{
		set_floor_color(map, lines[*i]);
		map->has_floor = 1;
	}
	else if (ft_strncmp(lines[*i], "C ", 2) == 0)
	{
		set_ceiling_color(map, lines[*i]);
		map->has_ceiling = 1;
	}
	(*i)++;
}

void	parse_texture_or_color_line(char **lines, int *i, t_map *map)
{
	if (is_blank(lines[*i]))
		(*i)++;
	else if (ft_strncmp(lines[*i], "NO ", 3) == 0 || ft_strncmp(lines[*i],
			"SO ", 3) == 0 || ft_strncmp(lines[*i], "WE ", 3) == 0
		|| ft_strncmp(lines[*i], "EA ", 3) == 0)
		parse_texture_line(lines, i, map);
	else if (ft_strncmp(lines[*i], "F ", 2) == 0 || ft_strncmp(lines[*i], "C ",
			2) == 0)
		parse_color_line(lines, i, map);
}

void	parse_textures_and_colors(char **lines, int *i, t_map *map)
{
	int	prev;

	while (lines[*i])
	{
		prev = *i;
		parse_texture_or_color_line(lines, i, map);
		if (*i == prev)
			break ;
	}
	if (!(map->has_no && map->has_so && map->has_we && map->has_ea
			&& map->has_floor && map->has_ceiling))
		error_exit("Missing textures or colors", NULL);
}
