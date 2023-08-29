#include "philo.h"

int		check_starve(t_data *data)
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

int		check_meal_count(t_data *data)
{
	int	i;
	int	ate_enuf_num;
	int	checkpoint;

	ate_enuf_num = 0;
	i = -1;
	checkpoint = data->meals_max * data->philo_num;
	if (data->meals_max == 0)
		return (0);
	pthread_mutex_lock(&data->check_lock_e);
	while (++i < data->philo_num)
		ate_enuf_num += data->ate_num[i];
	pthread_mutex_unlock(&data->check_lock_e);
	pthread_mutex_lock(&data->death_lock);
	if (ate_enuf_num >= checkpoint)
	{
		data->is_dead = 1;
		pthread_mutex_unlock(&data->death_lock);
		return (1);
	}
	pthread_mutex_unlock(&data->death_lock);
	return (0);
}

int		check_death(t_data *data)
{
	while (1)
	{
		if (check_starve(data) == 1 || check_meal_count(data))
			break ;
	}
	return (0);
}