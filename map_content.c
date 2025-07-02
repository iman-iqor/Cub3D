#include"header.h"
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
