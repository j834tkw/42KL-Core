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

//main
typedef struct	s_philo
{
	int             id;
	int             start_time;
	int             status;
	int             last_eaten;
	int				time_to_die;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
}	t_philo;

typedef struct	s_data
{
	pthread_t       *philo;
	int             philo_num;
	int             meals_num;
	int            	dead_num;
	int             finished_num;

	int			id;

	int			is_alive_bool;

	int			death_time;
	int			eat_time;
	int			sleep_time;
	int			start_time;

	pthread_mutex_t thread_lock;
	pthread_mutex_t *forks;
}	t_data;

// misc
void	check_data(t_data *data);
void	print_msg(t_data *data, char *msg, int id);
long int	get_time(void);

// thread create
int		create_thread(t_data *data);
int		join_thread(t_data *data);

void	*run_thread(t_data *data);

void	*routine(void *arg);

int		ft_atoi(char *str);

#endif