#include "philo.h"

void	check_data(t_data *data)
{
	if (data->philo_num <= 0 || data->eat_time < 60 || data->sleep_time < 60 ||
			data->death_time < 60)
	{
		printf("Invalid parameters\n");
		exit(1);
	}
	return ;
}

void	print_msg(t_data *data, char *msg, int id)
{
	long int	time;

	pthread_mutex_lock(&data->print_lock);
	time = get_time() - data->start_time ;//- 1692217114624;
	if (!strcmp("eating", msg))
		printf("%ld %d is eating\n", time, id+1);
	if (!strcmp("thinking", msg))
		printf("%ld %d is thinking\n", time, id+1);
	if (!strcmp("sleeping", msg))
		printf("%ld %d is sleeping\n", time, id+1);
	if (!strcmp("forking", msg))
		printf("%ld %d has taken a fork\n", time, id+1);
	if (!strcmp("dying", msg))
		printf("%ld %d has died\n", time, id+1);
	pthread_mutex_unlock(&data->print_lock);
	return ;
}

long int	get_time(void)
{
	struct timeval current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_usec / 1000 + current_time.tv_sec * 1000);
}

int	ft_atoi(char *str)
{
	int	i;
	int	nbr;
	int	n;

	i = 0;
	nbr = 0;
	n = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			n = -1;
	while (str[i] >= '0' && str[i] <= '9')
		nbr = nbr * 10 + (str[i++] - '0');
	nbr *= n;
	return (nbr);
}