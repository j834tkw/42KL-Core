#include "philo.h"

void	check_data(t_data *data)
{
	if (data->philo_num < 0 || data->philo_num > 200)
	{
		printf("Invalid parameters\n");
		exit(1);
	}
	return ;
}

void	print_msg(t_data *data, char *msg, int id)
{
	long int	time;

	time = get_time() - data->start_time;
	if (!strcmp("creation", msg))
		printf("%ld Wow me is philo no.%d\n", time, id);
	return ;
}

long int	get_time(void)
{
	struct timeval current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_usec / 1000 + current_time.tv_sec * 1000);
}