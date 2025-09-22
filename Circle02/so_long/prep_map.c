/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutong <jutong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:11:43 by jutong            #+#    #+#             */
/*   Updated: 2023/07/12 17:36:18 by jutong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_valid(t_data *data, char *file_name)
{
	int	valid;

	if (check_file_name(file_name) == 0)
	{
		write(1, "Invalid map file format\n", 24);
		exit(0);
	}
	valid = read_map(data, file_name);
	if (check_closed_map(data) == 0)
	{
		write(1, "Invalid map, map not closed\n", 28);
		exit(0);
	}
	if (check_chars(data) == 0)
	{
		write(1, "Invalid letters in map file\n", 28);
		exit(0);
	}
	count_coins(data);
	count_exits(data);
	count_players(data);
	check_valid_2(data);
}

void	check_valid_2(t_data *data)
{
	if (floodfill(data) == 0)
	{
		write(1, "Invalid map, no path to win\n", 28);
		exit(0);
	}
	if (data->exit_count != 1)
	{
		write(1, "Invalid map, number of exits not 1\n", 35);
		exit(0);
	}
	if (data->player_count != 1)
	{
		write(1, "Invalid map, number of players not 1\n", 37);
		exit(0);
	}
}

int	read_map(t_data *data, char *file_name)
{
	int		fd;
	char	*tmp;
	int		valid;

	fd = open(file_name, O_RDONLY);
	tmp = get_next_line(fd);
	while (tmp)
	{
		data->map_width = ft_strlen(tmp);
		data->map_height++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	if (tmp)
		free(tmp);
	if (data->map_height <= 2 || data->map_width <= 2)
		return (0);
	close(fd);
	valid = get_map(data, file_name);
	return (valid);
}

int	get_map(t_data *data, char *file_name)
{
	char	*str;
	int		bytes;
	int		fd;
	int		i;

	i = 0;
	fd = open(file_name, O_RDONLY);
	str = (char *)malloc(sizeof(char) * 10000);
	while (i++ < 10000)
		str[i] = '\0';
	bytes = read(fd, str, 9999);
	str[bytes] = '\0';
	data->map = ft_split(str, '\n');
	free(str);
	close(fd);
	return (1);
}
