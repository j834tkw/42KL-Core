#include "philo.h"

void	check_data(t_data *data)
{
	if (data->philo_num < 0 || data->philo_num > 200)
		print_exit("Invalid parameters\n");
	return ;
}

void	print_exit(char *str)
{
	printf("%s", str);
	exit (1);
}

long int	get_time(void)
{
	struct timeval current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_usec / 1000 + current_time.tv_sec * 1000);
}