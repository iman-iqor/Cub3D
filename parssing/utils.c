/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:52:08 by imiqor            #+#    #+#             */
/*   Updated: 2025/07/07 22:59:26 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../header.h"

char	*ft_ssstrjoin(char *save, char *buff)
{
	int		len;
	char	*str;
	int		i;
	int		j;

	if (!save && !buff)
		return (NULL);
	if (!save && buff)
		return (ftt_strdup(buff));
	if (save && !buff)
		return (ftt_strdup(save));
	len = ft_strlen(save) + ft_strlen(buff);
	str = ft_gc(len + 1,'m');
	if (!str)
		return (NULL);
	i = -1;
	while (save[++i] && i < ft_strlen(save))
		str[i] = save[i];
	j = 0;
	while (buff[j] && j < ft_strlen(buff))
		str[i++] = buff[j++];
	str[i] = 0;
	free(save);
	return (str);
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



void	error_exit(char *msg)
{
	write(2, "Error ", 7);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	ft_gc(0,'f');
	exit(EXIT_FAILURE);
}
char	*ftt_strdup(const char *s1)
{
	char	*str2;
	int		len;
	int		i;

	len = ft_strlen(s1);
	str2 =ft_gc(len + 1,'m');
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
