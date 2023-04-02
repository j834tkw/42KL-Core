#include "push_swap.h"

int	check_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < (stack->size_a - 1))
	{
		if (stack->stack_a[i] > stack->stack_a[i + 1])
			return (0);
	}
	if (stack->size_b != 0)
		return (0);
	free_and_exit(&stack, 0);
}

int	check_duplicate(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < stack->size_a)
	{
		j = 1;
		while (i + j < stack->size_a)
		{
			if (stack ->stack_a[i] == stack ->stack_a[i + j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_non_number(char **str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while(str[i][j])
	{
		while (ft_isspace(str[i][j]) || str[i][j] == '+' || str[i][j] == '-')
			j++;
		while (str[i][j])
		{
			if (str[i][j] < '0' || str[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
