/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:51:59 by imiqor            #+#    #+#             */
/*   Updated: 2025/09/21 16:35:08 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include"../header.h"

void	check_path(char *path)
{
	if (path == NULL)
		return ;
	// path[ft_strlen(path) - 1] = 0;
	if (!*path || access(path, F_OK) != 0)
	{
		error_exit("Texture path not accessible");
	}
}
char	*trim_spaces_end(char *str)
{
	int		len;
	char	*trimmed;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	while (len > 0 && (str[len - 1] == ' ' || str[len - 1] == '\n' || str[len - 1] == '\t'))
		len--;
	trimmed = ft_gc(len + 1,'m');
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, str, len + 1);
	return (trimmed);
}
void	assign_texture(t_map *map,char *line, char **dest, char *id)
{
	char	*path;
	char *clean;

	if(ft_strcmp(id,"NO") == 0 && map->has_no)
		error_exit("Duplicate NO texture");
	else if(ft_strcmp(id,"SO") == 0 && map->has_so)
		error_exit("Duplicate SO texture");
	else if(ft_strcmp(id,"WE") == 0 && map->has_we)
		error_exit("Duplicate WE texture");
	else if(ft_strcmp(id,"EA") == 0 && map->has_ea)
		error_exit("Duplicate EA texture");

	path = line + ft_strlen(id);
	while (*path == ' ')
		path++;
	clean = trim_spaces_end(path);
	check_path(clean);
	*dest = ftt_strdup(clean);
	if (!*dest)
		error_exit("Malloc failed for texture");
}


void	parse_textures_and_colors(char **lines, int *i, t_map *map)
{
	while (lines[*i])
	{
		if (lines[*i] && is_blank(lines[*i]))
			(*i)++;
		else if (ft_strncmp(lines[*i], "NO ", 3) == 0)
			assign_texture(map,lines[*i], &map->no, "NO"), map->has_no = 1, (*i)++;
		else if (ft_strncmp(lines[*i], "SO ", 3) == 0)
			assign_texture(map,lines[*i], &map->so, "SO"), map->has_so = 1, (*i)++;
		else if (ft_strncmp(lines[*i], "WE ", 3) == 0)
			assign_texture(map,lines[*i], &map->we, "WE"), map->has_we = 1, (*i)++;
		else if (ft_strncmp(lines[*i], "EA ", 3) == 0)
			assign_texture(map,lines[*i], &map->ea, "EA"), map->has_ea = 1, (*i)++;
		else if (ft_strncmp(lines[*i], "F ", 2) == 0)
			set_floor_color(map, lines[*i]), map->has_floor = 1, (*i)++;
		else if (ft_strncmp(lines[*i], "C ", 2) == 0)
			set_ceiling_color(map, lines[*i]), map->has_ceiling = 1, (*i)++;
		else
			break ;
	}
	if (!(map->has_no && map->has_so && map->has_we && map->has_ea
			&& map->has_floor && map->has_ceiling))
		error_exit("Missing textures or colors");
}
