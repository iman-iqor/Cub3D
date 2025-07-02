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
	write(2, "Error ", 7);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

static void	check_path(char *path)
{
	if (path == NULL)
		return ;
	// path[ft_strlen(path) - 1] = 0;
	printf("{%s}\n",path);
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
	trimmed = malloc(len + 1);
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, str, len + 1);
	return (trimmed);
}

static void	assign_texture(t_map *map,char *line, char **dest, char *id)
{
	char	*path;

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
	char *clean = trim_spaces_end(path);
	check_path(clean);
	*dest = ft_strdup(clean);
	if (!*dest)
		error_exit("Malloc failed for texture");
}

int	parse_rgb(char *line, int *r, int *g, int *b)
{
	char	**splited_line;
	int		count;

	splited_line = ft_split(line + 2, ',');
	if (!splited_line)
		return (0);
	count = 0;
	while (splited_line[count])
		count++;
	if (count != 3)
	{
		ftt_free(splited_line);
		return (0);
	}
	*r = ft_atoi(splited_line[0]);
	*g = ft_atoi(splited_line[1]);
	*b = ft_atoi(splited_line[2]);
	ftt_free(splited_line);
	if (*r < 0 || *r > 255 || *g < 0 || *g > 255 || *b < 0 || *b > 255)
		return (0);
	return (1);
}

static void	set_floor_color(t_map *map, char *line)
{
	int	r;
	int	g;
	int	b;

	if (map->has_floor)
		error_exit("Duplicate floor color");
	if (!parse_rgb(line, &r, &g, &b))
		error_exit("Invalid floor color");
	map->floor_r = r;
	map->floor_g = g;
	map->floor_b = b;
	map->has_floor = 1;
}

static void	set_ceiling_color(t_map *map, char *line)
{
	int	r;
	int	g;
	int	b;

	if (map->has_ceiling)
		error_exit("Duplicate ceiling color");
	if (!parse_rgb(line, &r, &g, &b))
		error_exit("Invalid ceiling color");
	map->ceiling_r = r;
	map->ceiling_g = g;
	map->ceiling_b = b;
	map->has_ceiling = 1;
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

int count_map_lines(char **content, int start)
{
    int count = 0;
    while (content[start + count])
        count++;
    return count;
}
void trim_newline(char *str)
{
    int len = ft_strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';
}

void store_map_lines(char **content, int start, t_map *map)
{
	int map_lines;
	int j;
	j = 0;
    map_lines = count_map_lines(content, start);
    map->map_grid = malloc(sizeof(char *) * (map_lines + 1));
    if (!map->map_grid)
        error_exit("Malloc failed for map grid");
    while (j < map_lines)
	{
        map->map_grid[j] = ft_strdup(content[start + j]);
		trim_newline(map->map_grid[j]); 
		j++;
	}
    map->map_grid[map_lines] = NULL; // Null terminate
    map->line_count = map_lines;

}

int is_valid_map_char(char c)
{
	if(c == '0' || c == '1' || c == ' ' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return 1;
    return (0);
}

void validate_map_chars(t_map *map)
{
	int player_count;
	char* line;
	int i;
	int j;
	j = 0;
	i = 0;
    player_count = 0;
    while(i < map->line_count)
    {
        line = map->map_grid[i];
		j = 0;
        while( line[j])
        {
            if (!is_valid_map_char(line[j]))
			{ 
                error_exit("Invalid character in map");
			}
            if (line[j] == 'N' || line[j] == 'S' || line[j] == 'E' || line[j] == 'W')
                player_count++;
			j++;
        }
		i++;
    }
    if (player_count != 1)
        error_exit("Map must have exactly one player start");
}

static void	validate_horizontal_border(char *line, char *err_msg)
{
	int	j = 0;

	while (line[j])
	{
		if (line[j] != '1' && line[j] != ' ')
			error_exit(err_msg);
		j++;
	}
}

static void	validate_vertical_borders(t_map *map)
{
	int		i;
	int		len;
	char	*line;

	i = 1;
	while (i < map->line_count - 1)
	{
		line = map->map_grid[i];
		len = ft_strlen(line);
		if (len == 0)
			error_exit("Empty line in map");
		if (line[0] != '1' && line[0] != ' ')
			error_exit("Left border must be walls");
		if (line[len - 1] != '1' && line[len - 1] != ' ')
			error_exit("Right border must be walls");
		i++;
	}
}

void	validate_map_borders(t_map *map)
{
	validate_horizontal_border(map->map_grid[0], "Top border must be walls");
	validate_horizontal_border(map->map_grid[map->line_count - 1], "Bottom border must be walls");
	validate_vertical_borders(map);
}
void validate_walls(t_map *map)
{
	int i  = 0;
	int j = 0;
	while(map->map_grid[i])
	{
		j = 0;
		while(map->map_grid[i][j])
		{
			if((map->map_grid[i][j] != '0' && map->map_grid[i][j] != '1' && map->map_grid[i][j] != 'N'))
			{
				write(2,"not sorrounded\n",16);
				exit(1);
			}
			j++;
		}
		i++;
	}
}


void parse_map(t_map *map, char **content, int start)
{
    store_map_lines(content, start, map);
    validate_map_chars(map);
	validate_walls(map);
    // validate_map_borders(map);
    // find player pos and store
}

void	check_map_content(char **content, t_map *map)
{
	int	i;

	i = 0;
	parse_textures_and_colors(map->map_two_d, &i, map);
	while (content[i] && ft_strcmp(content[i], "\n") == 0)
		i++;
	if (!content[i])
		write(2, "Map doesn't exist!\n", 20);
	check_no_blank_lines_inside_map(content, i);
	parse_map(map,content,i);
}
int	main(int argc, char **argv)
{
	t_map	map;

	ft_memset(&map, 0, sizeof(t_map));
	check_argc(argc);
	check_extention(argv[1]);
	check_if_file_exist(argv[1]);
	get_cub_content(argv[1], &map);
	check_map_content(map.map_two_d, &map);
	return (0);
}
