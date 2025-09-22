/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutong <jutong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 10:44:00 by jutong            #+#    #+#             */
/*   Updated: 2023/09/01 22:33:28 by jutong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_data	*data;
	int		id;

	data = (t_data *)arg;
	id = data->id;
	if (id % 2 == 1)
	{
		print_msg(data, "thinking", id);
		usleep((data->philo_num / 2) * data->eat_time);
	}
	action(data, id);
	return (NULL);
}

void	action(t_data *data, int id)
{
	while (1)
	{
		if (data->is_dead || data->yes_all_ate)
			break ;
		eat(data, id);
		if (data->is_dead || data->yes_all_ate)
			break ;
		print_msg(data, "sleeping", id);
		if (data->is_dead || data->yes_all_ate)
			break ;
		usleep(data->sleep_time * 1000);
		if (data->is_dead || data->yes_all_ate)
			break ;
		print_msg(data, "thinking", id);
		if (data->is_dead || data->yes_all_ate)
			break ;
	}
	return ;
}

void	eat(t_data *data, int id)
{
	pthread_mutex_lock(&data->forks[id]);
	if (data->is_dead)
	{
		pthread_mutex_unlock(&data->forks[id]);
		return ;
	}
	print_msg(data, "forking", id);
	pthread_mutex_lock(&data->forks[other_fork_num(data, id)]);
	if (data->is_dead)
	{
		pthread_mutex_unlock(&data->forks[other_fork_num(data, id)]);
		pthread_mutex_unlock(&data->forks[id]);
		return ;
	}
	print_msg(data, "forking", id);
	print_msg(data, "eating", id);
	pthread_mutex_lock(&data->eat_lock);
	data->last_ate[id] = get_time();
	data->ate_num[id] += 1;
	pthread_mutex_unlock(&data->eat_lock);
	usleep(data->eat_time * 1000);
	pthread_mutex_unlock(&data->forks[other_fork_num(data, id)]);
	pthread_mutex_unlock(&data->forks[id]);
	return ;
}

int	other_fork_num(t_data *data, int id)
{
	int	r_id;

	r_id = 0;
	if (id == data->philo_num - 1)
		r_id = 0;
	else
		r_id = id + 1;
	return (r_id);
}

void	*handle_one(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	print_msg(data, "forking", 0);
	usleep(data->death_time * 1000);
	print_msg(data, "dying", 0);
	return (NULL);
}
