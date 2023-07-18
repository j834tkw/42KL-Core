/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutong <jutong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:08:07 by jutong            #+#    #+#             */
/*   Updated: 2023/07/12 11:59:15 by jutong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_3d_arr(char **arr)
{
	free(arr);
	return ;
}

int	free_exit(t_data *data, int code)
{
	if (code == 1)
		write(1, "You win!!!\n", 11);
	free_3d_arr(data->map);
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}
