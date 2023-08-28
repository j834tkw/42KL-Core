#include "philo.h"

void	*routine(void *arg)
{
	t_data *data;
	int		id;

	data = (t_data *)arg;
	id = data->id;
	if (id % 2 == 1)
		usleep(100000);
	action(data, id);
	return (NULL);
}

void	action(t_data *data, int id)
{
	while (1)
	{
		if (data->is_dead)
			break ;
		eat(data, id);
		print_msg(data, "sleeping", id);
		usleep(data->sleep_time * 1000);
		print_msg(data, "thinking", id);
	}
	return ;
}

void	eat(t_data *data, int id)
{

	pthread_mutex_lock(&data->forks[id]);
	print_msg(data, "forking", id);
	pthread_mutex_lock(&data->forks[other_fork_num(data, id)]);
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

int		other_fork_num(t_data *data, int id)
{
	int	r_id;

	r_id = 0;
	if (id == data->philo_num - 1)
		r_id = 0;
	else
		r_id = id + 1;
	return (r_id);
}