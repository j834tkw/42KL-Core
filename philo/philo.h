/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutong <jutong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 10:43:50 by jutong            #+#    #+#             */
/*   Updated: 2023/08/29 13:21:57 by jutong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <stdio.h>
# include <fcntl.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	pthread_t		*philo;
	int				philo_num;
	int				id;
	int				is_dead;
	int				*ate_num;
	long int		*last_ate;

	int				meals_max;
	int				death_time;
	int				eat_time;
	int				sleep_time;
	int				start_time;

	pthread_mutex_t	thread_lock;
	pthread_mutex_t	death_lock;
	pthread_mutex_t	eat_lock;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	check_lock_s;
	pthread_mutex_t	check_lock_e;
	pthread_mutex_t	*forks;
}	t_data;

// thread check
int			check_starve(t_data *data);
int			check_meal_count(t_data *data, int *counter);
int			check_death(t_data *data);

// thread run
void		init_thread(t_data *data);
int			create_thread(t_data *data);
int			join_thread(t_data *data);

// thread main
void		*routine(void *arg);
void		action(t_data *data, int id);
void		eat(t_data *data, int id);
int			other_fork_num(t_data *data, int id);
void		*handle_one(void *arg);

// utils
void		check_data(t_data *data);
void		print_msg(t_data *data, char *msg, int id);
long int	get_time(void);
int			ft_atoi(char *str);
int			ft_strcmp(char *s1, char *s2);

#endif