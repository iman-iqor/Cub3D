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


int is_line_empty(char *line)
{
    int i = 0;
    if (!line)
        return 1;
    while (line[i])
    {
        if (line[i] != ' ' && line[i] != '\t')
            return 0;
        i++;
    }
    return 1;
}

int is_map_line(char *line)
{
    int i = 0;
    if (!line)
        return 0;
    while (line[i])
    {
        if (line[i] != '0' && line[i] != 'N' &&
            line[i] != 'S' && line[i] != 'E' && line[i] != 'W' &&
            line[i] != ' ' && line[i] != '\t')
            return 0;
        i++;
    }
    return 1;
}

char *join_lines(char *filename)
{
    char *line = NULL;
    char *joined = NULL;
    int fd = open(filename, O_RDONLY);
    int map_started = 0;

    if (fd < 0)
    {
        perror("Error opening file");
        exit(1);
    }
    line="a";

    while (line)
    {
        line = get_next_line(fd, 0);
        if (!map_started)
        {
            if (is_line_empty(line))
            {
                free(line);
                continue; // skip empty lines before map
            }
            else if (is_map_line(line))
            {
                map_started = 1;
            }
        }
        else // map has started
        {
            
            if (is_line_empty(line))
            {
                // printf("hi\n");
                free(line);
                write(2, "Error\nInvalid map: empty line inside map\n", 42);
                exit(1);
            }
            else if (!is_map_line(line))
            {
                free(line);
                write(2, "Error\nInvalid map: invalid characters in map\n", 46);
                exit(1);
            }
        }

        joined = ft_ssstrjoin(joined, line);
        free(line);
    }

    close(fd);

    if (!joined)
    {
        write(2, "Error\nEmpty file or no map found\n", 33);
        exit(1);
    }
    return joined;
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