#include "push_swap.h"

int	count_elements(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void ft_init_1_str(t_stack *stack, char **tmp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	stack->size_a = count_elements(tmp);
	stack->stack_a = malloc(sizeof(int) * stack->size_a);
	while (tmp[j])
	{
		stack->stack_a[i] = ft_check_atoi(tmp[j], tmp, stack);
		i++;
		j++;
	}
	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

void ft_init_more_str(t_stack *stack, char **av)
{
	int	i;

	i = 1;
	stack->size_a = count_elements(av) - 1;
	stack->stack_a = malloc(sizeof(int) * stack->size_a);
	while (av[i] != NULL)
	{
		stack->stack_a[i - 1] = ft_check_atoi(av[i], NULL, stack);
		i++;
	}
}

int	ft_fill_data(t_stack *stack, int ac, char **av)
{
	char	**tmp;

	if (ac == 2)
	{
		tmp = ft_split(av[1], ' ');
		ft_init_1_str(stack, tmp);
	}
	else if (ac > 2)
		ft_init_more_str(stack, av);
	stack->stack_b = malloc(sizeof(int) * stack->size_a);
	return (1);
}
