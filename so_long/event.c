#include "so_long.h"

void	event(t_data *data)
{
	collect_coin(data);
	if (data->coins_collected == data->coin_count)
		unlock_exit(data);
}

void	collect_coin(t_data *data)
{
	if (data->map[data->player_y][data->player_x] == 'C')
	{
		data->coins_collected++;
		data->map[data->player_y][data->player_x] = '0';
	}
}

void	unlock_exit(t_data *data)
{
	int	x;
	int	y;
	
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != 0)
		{
			if (data->map[y][x] == 'E')
			{
				mlx_put_image_to_window(data->mlx,
					data->win, data->floor_img, x * IMG_SIZE, y * IMG_SIZE);
				mlx_put_image_to_window(data->mlx,
					data->win, data->exit_2_img, x * IMG_SIZE, y * IMG_SIZE);
				return ;
			}
			x++;
		}
		y++;
	}
}
