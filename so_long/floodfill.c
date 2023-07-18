/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutong <jutong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:07:42 by jutong            #+#    #+#             */
/*   Updated: 2023/07/10 17:07:43 by jutong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**dupe(t_data *data)
{
	int		i;
	char	**tmp;

	i = 0;
	while (data->map[i] != NULL)
		i++;
	tmp = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (data->map[i] != NULL)
	{
		tmp[i] = ft_strdup(data->map[i]);
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

int	fill(char **tmp, t_data *data, int x, int y)
{
	int	up;
	int	down;
	int	left;
	int	right;

	if (tmp[y][x] == '1')
		return (1);
	if (tmp[y][x] == 'C')
		data->coin_count--;
	if (tmp[y][x] == 'E')
		data->exit_count--;
	tmp[y][x] = '1';
	up = fill(tmp, data, x, y + 1);
	down = fill(tmp, data, x, y - 1);
	left = fill(tmp, data, x - 1, y);
	right = fill(tmp, data, x + 1, y);
	return (1);
}

int	floodfill(t_data *data)
{
	char	**tmp;
	int		coins_in_map;
	int		exits_in_map;

	coins_in_map = data->coin_count;
	exits_in_map = data->exit_count;
	tmp = dupe(data);
	locate_player(data);
	fill(tmp, data, data->player_x, data->player_y);
	free_3d_arr(tmp);
	if ((data->coin_count == 0) && data->exit_count == 0)
	{
		data->coin_count = coins_in_map;
		data->exit_count = exits_in_map;
		return (1);
	}
	return (0);
}
