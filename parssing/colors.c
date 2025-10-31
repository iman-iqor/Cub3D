/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:51:10 by imiqor            #+#    #+#             */
/*   Updated: 2025/10/31 15:50:30 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	parse_rgb(char *line, int *r, int *g, int *b)
{
	char	**splited_line;
	int		count;

	splited_line = split_lines(line + 2, ',');
	if (!splited_line)
		return (0);
	count = 0;
	while (splited_line[count])
		count++;
	if (count != 3)
		return (0);
	*r = ft_atoi(splited_line[0]);
	*g = ft_atoi(splited_line[1]);
	*b = ft_atoi(splited_line[2]);
	if (*r < 0 || *r > 255 || *g < 0 || *g > 255 || *b < 0 || *b > 255)
		return (0);
	return (1);
}

unsigned int	rgb_to_hex(int r, int g, int b)
{
	if (r < 0)
	{
		r = 0;
	}
	if (r > 255)
	{
		r = 255;
	}
	if (g < 0)
	{
		g = 0;
	}
	if (g > 255)
	{
		g = 255;
	}
	if (b < 0)
	{
		b = 0;
	}
	if (b > 255)
	{
		b = 255;
	}
	return ((r << 16) | (g << 8) | b);
}

void	set_floor_color(t_map *map, char *line)
{
	int	r;
	int	g;
	int	b;

	if (map->has_floor)
		error_exit("Duplicate floor color", NULL);
	if (!parse_rgb(line, &r, &g, &b))
		error_exit("Invalid floor color", NULL);
	map->floor_color = rgb_to_hex(r, g, b);
}

void	set_ceiling_color(t_map *map, char *line)
{
	int	r;
	int	g;
	int	b;

	if (map->has_ceiling)
		error_exit("Duplicate ceiling color", NULL);
	if (!parse_rgb(line, &r, &g, &b))
		error_exit("Invalid ceiling color", NULL);
	map->ceiling_color = rgb_to_hex(r, g, b);
}
