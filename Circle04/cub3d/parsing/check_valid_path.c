/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:33:32 by jteoh             #+#    #+#             */
/*   Updated: 2024/01/26 11:27:46 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_valid_path(t_data *data)
{
	int	fd;

	fd = open(data->n_path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	fd = open(data->e_path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	fd = open(data->s_path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	fd = open(data->w_path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

int	check_file_exist(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}
