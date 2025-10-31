/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 22:53:07 by imiqor            #+#    #+#             */
/*   Updated: 2025/10/31 15:51:54 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	is_blank(char *s)
{
	while (*s)
	{
		if (*s != ' ' && *s != '\t' && *s != '\n')
			return (0);
		s++;
	}
	return (1);
}

void	check_no_blank_lines_inside_map(char **content, int start)
{
	int	i;
	int	map_started;

	i = start;
	map_started = 0;
	while (content[i])
	{
		if (is_blank(content[i]))
		{
			if (map_started)
				error_exit("Map contains empty line inside", NULL);
		}
		else
			map_started = 1;
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			break ;
	}
	return (s1[i] - s2[i]);
}

char	*ftt_strdup(const char *s1)
{
	char	*str2;
	int		len;
	int		i;

	len = ft_strlen(s1);
	str2 = ft_gc(len + 1, 'm');
	if (!str2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str2[i] = s1[i];
		i++;
	}
	str2[i] = 0;
	return (str2);
}
