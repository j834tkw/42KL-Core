/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutong <jutong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:07:36 by jutong            #+#    #+#             */
/*   Updated: 2023/07/10 17:07:37 by jutong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	event(t_data *data)
{
	collect_coin(data);
}

void	collect_coin(t_data *data)
{
	if (data->map[data->player_y][data->player_x] == 'C')
	{
		data->coins_collected++;
		data->map[data->player_y][data->player_x] = '0';
	}
}
