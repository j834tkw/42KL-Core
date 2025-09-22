/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutong <jutong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:09:57 by jutong            #+#    #+#             */
/*   Updated: 2023/07/12 17:26:22 by jutong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_data(t_data *data)
{
	data->map_width = 0;
	data->map_height = 0;
	data->coin_count = 0;
	data->exit_count = 0;
	data->player_count = 0;
	data->coins_collected = 0;
	data->movement_count = 0;
	data->movement_bool = 0;
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (0);
	init_data(&data);
	check_valid(&data, av[1]);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx,
			data.map_width * IMG_SIZE, data.map_height * IMG_SIZE, "so_long");
	init_image(&data);
	locate_player(&data);
	mlx_loop_hook(data.mlx, image_loop, &data);
	mlx_key_hook(data.win, movement, &data);
	mlx_hook(data.win, ON_DESTROY, 0, free_exit, &data);
	mlx_loop(data.mlx);
}
