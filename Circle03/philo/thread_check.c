/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutong <jutong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 10:43:55 by jutong            #+#    #+#             */
/*   Updated: 2023/09/01 15:49:53 by jutong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_starve(t_data *data)
{
	int			i;
	long int	diff;

	i = -1;
	while (++i < data->philo_num)
	{
		pthread_mutex_lock(&data->check_lock_s);
		diff = get_time() - data->last_ate[i];
		if (diff > data->death_time)
		{
			print_msg(data, "dying", i);
			data->is_dead = 1;
			pthread_mutex_unlock(&data->check_lock_s);
			return (1);
		}
		pthread_mutex_unlock(&data->check_lock_s);
	}
	return (0);
}

int	check_meal_count(t_data *data, int *counter)
{
	int	i;

	i = -1;
	if (data->meals_max == 0)
		return (0);
	pthread_mutex_lock(&data->check_lock_e);
	while (++i < data->philo_num)
		if (data->ate_num[i] == data->meals_max + 1)
			*counter += 1;
	pthread_mutex_unlock(&data->check_lock_e);
	pthread_mutex_lock(&data->death_lock);
	if (*counter >= data->philo_num)
	{
		data->yes_all_ate = 1;
		pthread_mutex_unlock(&data->death_lock);
		return (1);
	}
	pthread_mutex_unlock(&data->death_lock);
	return (0);
}

int	check_death(t_data *data)
{
	int	counter;

	counter = 0;
	while (1)
	{
		if (check_starve(data) == 1 || check_meal_count(data, &counter))
			break ;
	}
	return (0);
}
