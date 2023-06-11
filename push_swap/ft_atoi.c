#include "push_swap.h"

int	ft_check_atoi(const char *str, char **to_free, t_stack *to_free_2)
{
	int		i;
	long	nbr;
	int		n;

	i = 0;
	nbr = 0;
	n = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			n = -1;
	if (str[i] == 0)
		free_and_exit_both(to_free, to_free_2);
	while (str[i] != 0)
	{
		if (str[i] < '0' || str[i] > '9')
			free_and_exit_both(to_free, to_free_2);
		nbr = nbr * 10 + (str[i++] - '0');
	}
	nbr *= n;
	if (nbr > 2147483647 || nbr < -2147483648)
		free_and_exit_both(to_free, to_free_2);
	return ((int)nbr);
}
