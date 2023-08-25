#include "philo.h"

void	*routine(void *arg)
{
	t_data *data;

	data = (t_data *)arg;
	print_msg(data, "creation", data->id);
	if (data->id % 2 == 1)
		usleep(10000);
//	action(data);
	return (NULL);
}

/*
void	action(t_data *data)
{
	while (data->is_alive_bool)
	{
		if (data->is_alive_bool)
			philo_eat(data, data->id);
		if (data->is_alive_bool)
			philo_think(data, data->id);
	}
	return (NULL);
}
*/

//void	check_dead(t_data *data)

/*
void	philo_eat(t_data *data, int id)
{
	pthread_mutex_lock(&(data->forks[id]));
	if (id == 0)
		pthread_mutex_lock(&data->forks[data->philo_num - 1]);
	else
		pthread_mutex_lock(&data->forks[id - 1]);
}
*/