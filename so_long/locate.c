#include "so_long.h"

void	locate_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != 0)
		{
			if (data->map[i][j] == 'P')
			{
				data->player_x = j;
				data->player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	count_coins(t_data *data)
{
	int	x;
	int	y;

	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != 0)
		{
			if (data->map[y][x] == 'C')
				data->coin_count++;
			x++;
		}
		y++;
	}
}
