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

int	nbr_of_lines(char *filename)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror(filename);
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd, 0);
	while (line)
	{
		free(line);
		i++;
		line = get_next_line(fd, 0);
	}
	close(fd);
	return (i);
}
void	get_cub_content(char *argv, t_map *map)
{
	int	len;
	int	fd;
	int	i;

	i = 0;
	len = nbr_of_lines(argv);
	map->line_count = len;
	map->map_two_d = malloc(sizeof(char *) * (len + 1));
	if (!map->map_two_d)
		write(2, "Malloc Error: parser.c: 81\n", 28);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		perror(argv);
		exit(EXIT_FAILURE);
	}
	map->map_two_d[i] = get_next_line(fd, 0);
	while (i < len && map->map_two_d[i++])
		map->map_two_d[i] = get_next_line(fd, 0);
	map->map_two_d[i] = 0;
	close(fd);
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
	// maybe i should close the fd here
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
void	check_cub_texture(char **content, int *i)
{
	int	found;

	found = 0;
	while (*i < 4 && content[*i])
	{
		if (ft_strncmp(content[*i], "NO ", 3) == 0 || ft_strncmp(content[*i],
				"SO ", 3) == 0 || ft_strncmp(content[*i], "WE ", 3) == 0
			|| ft_strncmp(content[*i], "EA ", 3) == 0)
			found++;
		(*i)++;
	}
	if (found != 4 && *i != found)
		write(2, "Texture error!\n", 16);
	if (*i == 0)
		write(2, "Empty .cub file!\n", 18);
}

void	check_cub_colors(char **content, int *i)
{
	int	found;
	int	j;
	int	ex;

	found = 0;
	ex = *i;
	j = *i + 2;
	printf("this is j : %d\n", j);
	while (*i < j && content[*i])
	{
		printf("this is i : %d\n", *i);
		if (ft_strncmp(content[*i], "F ", 2) == 0 || ft_strncmp(content[*i],
				"C ", 2) == 0)
			found++;
		(*i)++;
	}
	if (*i - ex != found && found != 2)
		write(2, "Colors error\n", 14);
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

void	error_exit(char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

static void	check_path(char *path)
{
	if (path == NULL)
		return;
	path[ft_strlen(path)-1] = 0;
	if (!*path || access(path, R_OK) != 0)
	{
		error_exit("Texture path not accessible");
	}
}

static void	assign_texture(char *line, char **dest, char *id)
{
	char	*path;

	path = line + ft_strlen(id);
	while (*path == ' ')
		path++;
	check_path(path);
	*dest = ft_strdup(path);
	if (!*dest)
		error_exit("Malloc failed for texture");
}

static int	is_texture(char *line, t_map *map)
{
	if (!map->has_no && ft_strncmp(line, "NO ", 3) == 0)
		return (1);
	if (!map->has_so && ft_strncmp(line, "SO ", 3) == 0)
		return (2);
	if (!map->has_we && ft_strncmp(line, "WE ", 3) == 0)
		return (3);
	if (!map->has_ea && ft_strncmp(line, "EA ", 3) == 0)
		return (4);
	return (0);
}

void	check_cub_textures2(char **lines, int *i, t_map *map)
{
	int	code;

	while (lines[*i])
	{
		if (is_blank(lines[*i]))
			(*i)++;
		else
		{
			code = is_texture(lines[*i], map);
			if (code == 1)
				assign_texture(lines[*i], &map->no, "NO"), map->has_no = 1;
			else if (code == 2)
				assign_texture(lines[*i], &map->so, "SO"), map->has_so = 1;
			else if (code == 3)
				assign_texture(lines[*i], &map->we, "WE"), map->has_we = 1;
			else if (code == 4)
				assign_texture(lines[*i], &map->ea, "EA"), map->has_ea = 1;
			else
				break ;
			(*i)++;
		}
	}
	if (!(map->has_no && map->has_so && map->has_we && map->has_ea))
		error_exit("Missing texture");
}


void	check_map_content(char **content,t_map *map)
{
	int	i;

	i = 0;
	check_cub_textures2(content, &i,map);
	while (content[i] && ft_strcmp(content[i], "\n") == 0)
		i++;
	check_cub_colors(content, &i);
	while (content[i] && ft_strcmp(content[i], "\n") == 0)
		i++;
	if (!content[i])
		write(2, "Map doesn't exist!\n", 20);
}
int	main(int argc, char **argv)
{
	t_map	map;

	ft_memset(&map, 0, sizeof(t_map));
	check_argc(argc);
	check_extention(argv[1]);
	check_if_file_exist(argv[1]);
	get_cub_content(argv[1], &map);
	check_map_content(map.map_two_d,&map);
	return (0);
}
