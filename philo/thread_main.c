#include "philo.h"

void	*routine(void *arg)
{
	t_data *data;

	data = (t_data *)arg;
	printf("Wow, me is philo no.%d\n", data->id);
	return (NULL);
}
