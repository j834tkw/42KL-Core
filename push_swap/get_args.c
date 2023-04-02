#include "push_swap.h"

int	count_elements(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

// Mallocs new stack, copies data from old stack to new
// Then copies splitted data to new stack
void	realloc_stack(t_stack *stack, char **to_add)
{
	int	*new_stack_a;
	int	i;
	int	j;
	int	new_size;

	i = 0;
	j = 0;
	new_size = (count_elements(to_add) + stack->size_a);
	new_stack_a = malloc(sizeof(int) * new_size);
	while (i++ < stack->size_a)
		new_stack_a[i] = stack->stack_a[i];
	while (to_add[j])
	{
		new_stack_a[i] = ft_atoi(to_add[j], to_add);
		i++;
		j++;
	}
	if (stack->stack_a)
		free(stack->stack_a);
	stack->stack_a = new_stack_a;
	stack->size_a = new_size;
}

int	ft_fill_data(t_stack *stack, int ac, char **av)
{
	char	**tmp;
	int		i;
	int		i_free;

	i = 1;
	while (i < ac)
	{
		tmp = ft_split(av[i], ' ');
		realloc_stack(stack, tmp);
		i_free = 0;
		while (tmp[i_free])
		{
			free(tmp[i_free]);
			i_free++;
		}
		free(tmp);
		i++;
	}
	return (1);
}
