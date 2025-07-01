#include "header.h"
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
void	join_lines_error(char *s, char *str)
{
	write(2, "Error\n :invalid map has newlines\n", 34);
	free(s);
	free(str);
	exit(1);
}

char	*join_lines(char *argv)
{
	char	*s;
	char	*str;
	int		fd;

	str = NULL;
	s = "a";
	fd = open(argv, O_RDONLY);;
	while (s)
	{
		s = get_next_line(fd, 0);
		if (!(ft_strncmp(s, "\n", 1)))
		{
			get_next_line(fd, 1);
			join_lines_error(s, str);
		}
		if (s)
			str = ft_ssstrjoin(str, s);
		free(s);
	}
	if (!str)
	{
		write(1, "Error the file is empty\n", 25);
		exit(1);
	}
	return (str);
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
    //maybe i should the fd here
	return fd;
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
	if (argc == 1)
	{
		write(1, "Error \nu should add the file that contains the map\n", 52);
		exit(1);
	}
}
int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_map map;
	ft_memset(&map, 0, sizeof(t_map));
	check_argc(argc);
	check_extention(argv[1]);
    
	check_if_file_exist(argv[1]);
    map.lines = join_lines(argv[1]);
	return (0);
}