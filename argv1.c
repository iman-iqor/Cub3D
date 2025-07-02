#include"header.h"
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
