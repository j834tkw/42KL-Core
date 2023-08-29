/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutong <jutong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 10:44:14 by jutong            #+#    #+#             */
/*   Updated: 2023/08/29 17:06:06 by jutong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_data(t_data *data)
{
	if (data->philo_num <= 0 || data->eat_time < 60 || data->sleep_time < 60
		|| data->death_time < 60)
	{
		printf("Invalid parameters\n");
		exit(1);
	}
	return ;
}

void	print_msg(t_data *data, char *msg, int id)
{
	unsigned long int	time;
	unsigned long int	current_time;

	pthread_mutex_lock(&data->print_lock);
	current_time = get_time();
	time = current_time - data->start_time;
	if (!ft_strcmp("eating", msg))
		printf("%ld %d is eating\n", time, id + 1);
	if (!ft_strcmp("thinking", msg))
		printf("%ld %d is thinking\n", time, id + 1);
	if (!ft_strcmp("sleeping", msg))
		printf("%ld %d is sleeping\n", time, id + 1);
	if (!ft_strcmp("forking", msg))
		printf("%ld %d has taken a fork\n", time, id + 1);
	if (!ft_strcmp("dying", msg))
		printf("%ld %d has died\n", time, id + 1);
	pthread_mutex_unlock(&data->print_lock);
	return ;
}

unsigned long int	get_time(void)
{
	struct timeval	current_time;

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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
