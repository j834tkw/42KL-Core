#include "push_swap.h"

void	detect_alpha_free(const char *str, char **to_free, t_stack *to_free_2)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
			free_and_exit_both(to_free, to_free_2);
		i++;
	}
}

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
	detect_alpha_free(str, to_free, to_free_2);
	while (str[i] >= '0' && str[i] <= '9')
		nbr = nbr * 10 + (str[i++] - '0');
	nbr *= n;
	if (nbr > 2147483647 || nbr < -2147483648)
		free_and_exit_both(to_free, to_free_2);
	return ((int)nbr);
}
