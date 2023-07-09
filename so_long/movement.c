#include "so_long.h"

void	move_up(t_data *data)
{
	if (data->map[(data->player_y) - 1][data->player_x] == 'E'
		&& data->coins_collected != data->coin_count)
		return ;
	if (data->map[(data->player_y) - 1][data->player_x] == 'E'
		&& data->coins_collected == data->coin_count)
		free_exit(data, 1);
	data->player_y -= 1;
	data->movement_count++;
	data->movement_bool = 1;
}

void	move_left(t_data *data)
{
	if (data->map[data->player_y][(data->player_x) - 1] == 'E'
		&& data->coins_collected != data->coin_count)
		return ;
	if (data->map[data->player_y][(data->player_x) - 1] == 'E'
		&& data->coins_collected == data->coin_count)
		free_exit(data, 1);
	data->player_x -= 1;
	data->movement_count++;
	data->movement_bool = 1;
}

void	move_down(t_data *data)
{
	if (data->map[(data->player_y) + 1][data->player_x] == 'E'
		&& data->coins_collected != data->coin_count)
		return ;
	if (data->map[(data->player_y) + 1][data->player_x] == 'E'
		&& data->coins_collected == data->coin_count)
		free_exit(data, 1);
	data->player_y += 1;
	data->movement_count++;
	data->movement_bool = 1;
}

void	move_right(t_data *data)
{
	if (data->map[data->player_y][(data->player_x) + 1] == 'E'
		&& data->coins_collected != data->coin_count)
		return ;
	if (data->map[data->player_y][(data->player_x) + 1] == 'E'
		&& data->coins_collected == data->coin_count)
		free_exit(data, 1);
	data->player_x += 1;
	data->movement_count++;
	data->movement_bool = 1;
}

int	movement(int keycode, t_data *data)
{
	if (keycode == 27)
		free_exit(data, 0);
	else if (keycode == 'w' && data->map[(data->player_y) - 1][data->player_x] != '1')
		move_up(data);
	else if (keycode == 's' && data->map[(data->player_y) + 1][data->player_x] != '1')
		move_down(data);
	else if (keycode == 'a' && data->map[data->player_y][(data->player_x) - 1] != '1')
		move_left(data);
	else if (keycode == 'd' && data->map[data->player_y][(data->player_x) + 1] != '1')
		move_right(data);
	event(data);
	if (data->movement_bool == 1)
	{
		ft_putnbr_fd(data->movement_count, 1);
		write(1, "\n", 1);
		data->movement_bool = 0;
	}
	return (0);
}
