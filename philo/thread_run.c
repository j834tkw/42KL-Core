#include "philo.h"

void	init_thread(t_data *data)
{
	int	i;

	i = 0;
	data->philo = (pthread_t *) malloc (sizeof(pthread_t) * data->philo_num);
	data->forks = (pthread_mutex_t *) malloc (sizeof(pthread_mutex_t) * data->philo_num);
	pthread_mutex_init(&data->check_lock, NULL);
	pthread_mutex_init(&data->print_lock, NULL);
	pthread_mutex_init(&data->eat_lock, NULL);
	pthread_mutex_init(&data->death_lock, NULL);
	pthread_mutex_init(&data->thread_lock, NULL);
	while (i < data->philo_num)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
}

int		create_thread(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
	{
		pthread_mutex_lock(&data->thread_lock);
		data->id = i;
		data->last_ate[i] = get_time();
		pthread_mutex_unlock(&data->thread_lock);
		pthread_create(&data->philo[i], NULL, (void *)routine, (void *)data);
		usleep (100);
	}
	return (0);
}

int		join_thread(t_data *data)
{
	int	i;
	int	n;

	i = 0;
	n = data->philo_num;
	while (i < n)
	{
		pthread_join(data->philo[i], NULL);
		i++;
	}
	return (0);
}
