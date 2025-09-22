/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutong <jutong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:10:06 by jutong            #+#    #+#             */
/*   Updated: 2023/07/12 12:06:13 by jutong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (keycode == 53)
		free_exit(data, 2);
	else if (keycode == 13
		&& data->map[(data->player_y) - 1][data->player_x] != '1')
		move_up(data);
	else if (keycode == 1
		&& data->map[(data->player_y) + 1][data->player_x] != '1')
		move_down(data);
	else if (keycode == 0
		&& data->map[data->player_y][(data->player_x) - 1] != '1')
		move_left(data);
	else if (keycode == 2
		&& data->map[data->player_y][(data->player_x) + 1] != '1')
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
