#include "so_long.h"

void	check_valid(t_data *data, char *file_name)
{
	int	valid;

	if (check_file_name(file_name) == 0)
	{
		printf("Invalid map file format\n");
		exit(0);
	}
	valid = read_map(data, file_name);
	count_coins(data);
	if (check_closed_map(data) == 0)
	{
		printf("Invalid map, map not closed\n");
		exit(0);
	}
	if (check_chars(data) == 0)
	{
		printf("Invalid letters in map file\n");
		exit(0);
	}
	if (floodfill(data) == 0)
	{
		printf("Invalid map, no path to win\n");
		exit(0);
	}	
}

int	read_map(t_data *data, char *file_name)
{
	int		fd;
	char	*tmp;
	int		valid;

	fd = open(file_name, O_RDONLY);
	tmp = get_next_line(fd);
	while (tmp)
	{
		data->map_width = ft_strlen(tmp);
		data->map_height++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	if (tmp)
		free(tmp);
	if (data->map_height <= 2 || data->map_width <= 2)
		return (0);
	close(fd);
	valid = get_map(data, file_name);
	return (valid);
}

int	get_map(t_data *data, char *file_name)
{
	char	*str;
	int		bytes;
	int		fd;
	int		i = 0;

	fd = open(file_name, O_RDONLY);
	str = (char *)malloc(sizeof(char) * 10000);
	bytes = read(fd, str, 9999);
	str[bytes] = '\0';
	data->map = ft_split(str, '\n');
	free(str);
	close(fd);
	return (1);
}
