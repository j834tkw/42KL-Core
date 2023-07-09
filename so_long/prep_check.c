#include "so_long.h"

int	check_chars(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != 0)
		{
			if (data->map[y][x] != 'P' && data->map[y][x] != 'C'
				&& data->map[y][x] != 'E' && data->map[y][x] != '1'
				&& data->map[y][x] != '0')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_file_name(char *file_name)
{
	int	i;

	i = 0;
	while (file_name[i] != 0)
		i++;
	i--;
	if (file_name[i] != 'r')
		return (0);
	i--;
	if (file_name[i] != 'e')
		return (0);
	i--;
	if (file_name[i] != 'b')
		return (0);
	i--;
	if (file_name[i] != '.')
		return (0);
	return (1);
}

int	check_closed_map(t_data *data)
{
	int	i;
	int k;

	i = 1;
	k = 0;
	while (k < data->map_width)
		if (data->map[0][k++] != '1')
			return (0);
	k = 0;
	while (i++ < data->map_height - 1)
	{
		if (data->map[i][0] != '1' || data->map[i][data->map_width - 1] != '1')
			return (0);
	}
	while (k < data->map_width)
		if (data->map[data->map_height - 1][k++] != '1')
			return (0);
	return (1);
}