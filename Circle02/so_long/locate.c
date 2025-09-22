/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutong <jutong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:09:48 by jutong            #+#    #+#             */
/*   Updated: 2023/07/12 17:26:31 by jutong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	locate_player(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != 0)
		{
			if (data->map[y][x] == 'P')
			{
				data->player_x = x;
				data->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	count_coins(t_data *data)
{
	int	x;
	int	y;

	y = 0;
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
	return (1);
}

int	count_exits(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != 0)
		{
			if (data->map[y][x] == 'E')
				data->exit_count++;
			x++;
		}
		y++;
	}
	return (1);
}

int	count_players(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != 0)
		{
			if (data->map[y][x] == 'P')
				data->player_count++;
			x++;
		}
		y++;
	}
	return (1);
}
