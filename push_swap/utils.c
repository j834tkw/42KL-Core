#include "push_swap.h"

int	ft_check_atoi(const char *str, char **to_free, t_stack *to_free_2)
{
	int	i;
	long	nbr;
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
	if (nbr > 2147483647 || nbr < -2147483648)
		free_and_exit_both(to_free, to_free_2);
	return ((int)nbr);
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	return ;
}

int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	*ft_array_dup(int *arr, int size)
{
	int		i;
	int		*dest;

	i = 0;
	dest = (int *) malloc(sizeof(int) * size);
	if (dest == 0)
		return (0);
	while (i < size)
	{
		dest[i] = arr[i];
		i++;
	}
//	printf("duped\n");
	return (dest);
}
