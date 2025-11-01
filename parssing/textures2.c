/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:40:40 by imiqor            #+#    #+#             */
/*   Updated: 2025/11/01 18:42:54 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	check_path(char *path)
{
	if (path == NULL)
		return ;
	if (!*path || access(path, F_OK) != 0)
	{
		error_exit("Texture path not accessible", NULL);
	}
}

char	*trim_spaces_end(char *str)
{
	int		len;
	char	*trimmed;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	while (len > 0 && (str[len - 1] == ' ' || str[len - 1] == '\n'))
		len--;
	trimmed = ft_gc(len + 1, 'm');
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, str, len + 1);
	return (trimmed);
}
