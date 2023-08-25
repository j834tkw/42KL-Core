#include "philo.h"

//number_of_philosophers   time_to_die   time_to_eat   time_to_sleep   [number_of_times_each_philosopher_must_eat]//

void	init_data(t_data *data, int ac, char **av)
{
	data->philo_num = ft_atoi(av[1]);

//	data->death_time = ft_atoi(av[2]);
//	data->eat_time = ft_atoi(av[3]);
//	data->sleep_time = ft_atoi(av[4]);
//	if (ac == 6)
//		data->meals_num = ft_atoi(av[5]);
//	else
//		data->meals_num = -1;
	data->id = 0;
	data->start_time = get_time();
	data->is_alive_bool = 1;
//	data->dead_num = 0;
//	data->finished_num = 0;
	(void)ac;
}

void	init_thread(t_data *data)
{
	int	i;

	i = 0;
	data->philo = (pthread_t *) malloc (sizeof(pthread_t) * data->philo_num);
	data->forks = (pthread_mutex_t *) malloc (sizeof(pthread_mutex_t) * data->philo_num);
//	pthread_mutex_init(&data->write, NULL);
//	pthread_mutex_init(&data->eat_lock, NULL);
//	pthread_mutex_init(&data->death_lock, NULL);
	pthread_mutex_init(&data->thread_lock, NULL);
	while (i < data->philo_num)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
}

int	main (int ac, char **av)
{
	t_data	data;

//	if (ac != 5 || ac != 6)
//		return (0);
	init_data(&data, ac, av);
	check_data(&data);
	init_thread(&data);
	if (create_thread(&data) != 0)
		return (1);
	join_thread(&data);
}
