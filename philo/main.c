#include "philo.h"

void	init_data(t_data *data, int ac, char **av)
{
	int	i;

	i = 0;
	data->philo_num = ft_atoi(av[1]);
	data->death_time = ft_atoi(av[2]);
	data->eat_time = ft_atoi(av[3]);
	data->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		data->meals_max = ft_atoi(av[5]);
	else
		data->meals_max = 0;
	check_data(data);
	data->id = 0;
	data->ate_num = (int *) malloc (sizeof(int) * data->philo_num);
	while (i++ < data->philo_num)
		data->ate_num[i] = 0;
	data->last_ate = (long int *) malloc (sizeof(long int) * data->philo_num);
	data->start_time = get_time();
	data->is_dead = 0;
}

void	free_all(t_data *data)
{
	int	i;

	i = 0;
	free (data->ate_num);
	free (data->last_ate);
	free (data->philo);
	while (i++ < data->philo_num)
		pthread_mutex_destroy(&data->forks[i]);
	pthread_mutex_destroy(&data->check_lock_s);
	pthread_mutex_destroy(&data->check_lock_e);
	pthread_mutex_destroy(&data->print_lock);
	pthread_mutex_destroy(&data->eat_lock);
	pthread_mutex_destroy(&data->death_lock);
	pthread_mutex_destroy(&data->thread_lock);
}

int	main (int ac, char **av)
{
	t_data	data;

	if (ac != 5 && ac != 6)
		return (0);
	init_data(&data, ac, av);
	init_thread(&data);
	create_thread(&data);
	check_death(&data);
	join_thread(&data);
//	free_all(&data);
}
