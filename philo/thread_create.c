#include "philo.h"

int		create_thread(t_data *data)
{
	int	i;

	i = 1;
	while (i <= data->philo_num)
	{
		if (pthread_create(&data->philo[i], NULL, (void *)routine, (void *)data) != 0)
			return (1);
		usleep (100);
		pthread_mutex_lock(&data->thread_lock);
//		printf("%d\n", i);
		data->id = i;
		i++;
		pthread_mutex_unlock(&data->thread_lock);
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
