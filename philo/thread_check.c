#include "philo.h"

int		check_starve(t_data *data)
{
	int			i;
	long int	diff;

	while (1)
	{
		i = -1;
		while (++i < data->philo_num)
		{
			pthread_mutex_lock(&data->check_lock);
			diff = get_time() - data->last_ate[i];
			if (diff > data->death_time)
			{
//				printf("%ld vs %d\n", diff, data->death_time);
				print_msg(data, "dying", i);
				data->is_dead = 1;
				pthread_mutex_unlock(&data->check_lock);
				return (0);
			}
			pthread_mutex_unlock(&data->check_lock);
		}
	}
	return (0);
}
/*
int		check_meal_count(t_data *data)
{

}
*/