/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutong <jutong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:08:35 by jutong            #+#    #+#             */
/*   Updated: 2023/07/12 11:49:59 by jutong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_image(t_data *data)
{
	int	img_width;
	int	img_height;

	data->floor_img = mlx_xpm_file_to_image(data->mlx,
			"./textures/floor.xpm", &img_width, &img_height);
	data->wall_img = mlx_xpm_file_to_image(data->mlx,
			"./textures/wall.xpm", &img_width, &img_height);
	data->coin_img = mlx_xpm_file_to_image(data->mlx,
			"./textures/coin.xpm", &img_width, &img_height);
	data->exit_img = mlx_xpm_file_to_image(data->mlx,
			"./textures/exit.xpm", &img_width, &img_height);
	data->player_img = mlx_xpm_file_to_image(data->mlx,
			"./textures/player.xpm", &img_width, &img_height);
}

void	put_img(t_data *data, int x, int y)
{
	if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx,
			data->win, data->wall_img, x * IMG_SIZE, y * IMG_SIZE);
	if (data->map[y][x] == '0')
	{
		mlx_put_image_to_window(data->mlx,
			data->win, data->floor_img, x * IMG_SIZE, y * IMG_SIZE);
	}
	if (data->map[y][x] == 'P')
		mlx_put_image_to_window(data->mlx,
			data->win, data->floor_img, x * IMG_SIZE, y * IMG_SIZE);
	if (data->map[y][x] == 'C')
	{
		mlx_put_image_to_window(data->mlx,
			data->win, data->floor_img, x * IMG_SIZE, y * IMG_SIZE);
		mlx_put_image_to_window(data->mlx,
			data->win, data->coin_img, x * IMG_SIZE, y * IMG_SIZE);
	}
	if (data->map[y][x] == 'E')
	{
		mlx_put_image_to_window(data->mlx,
			data->win, data->floor_img, x * IMG_SIZE, y * IMG_SIZE);
		mlx_put_image_to_window(data->mlx,
			data->win, data->exit_img, x * IMG_SIZE, y * IMG_SIZE);
	}
}

void	put_map_img_to_win(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\n')
		{
			put_img(data, x, y);
			x++;
		}
		y++;
	}
}

int	image_loop(t_data *data)
{
	put_map_img_to_win(data);
	mlx_put_image_to_window(data->mlx, data->win, data->floor_img,
		data->player_x * IMG_SIZE, data->player_y * IMG_SIZE);
	mlx_put_image_to_window(data->mlx, data->win, data->player_img,
		data->player_x * IMG_SIZE, data->player_y * IMG_SIZE);
	return (1);
}
