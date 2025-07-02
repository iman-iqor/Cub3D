#include"header.h"
char	*ft_ssstrjoin(char *save, char *buff)
{
	int		len;
	char	*str;
	int		i;
	int		j;

	if (!save && !buff)
		return (NULL);
	if (!save && buff)
		return (ft_strdup(buff));
	if (save && !buff)
		return (ft_strdup(save));
	len = ft_strlen(save) + ft_strlen(buff);
	str = malloc(len + 1);
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
	exit(EXIT_FAILURE);
}



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

void check_no_blank_lines_inside_map(char **content, int start)
{
    int i = start;
    int map_started = 0;

    while (content[i])
    {
        if (is_blank(content[i]))
        {
            if (map_started)
                error_exit("Map contains empty line inside");
        }
        else
        {
            map_started = 1;
        }
        i++;
    }
}