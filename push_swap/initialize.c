#include "push_swap.h"

void	ft_initialize_struct(t_stack *stack)
{
	stack->stack_a = NULL;
	stack->stack_b = NULL;
	stack->size_a = 0;
	stack->size_b = 0;
	stack->instruction_count = 0;
}

void	insertion_sort(int *arr, int n)
{
	int	i;
	int	j;
	int	tmp;

	i = 1;
	while (i < n)
	{
		tmp = arr[i];
		j = i - 1;
		while (arr[j] > tmp && j >= 0)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = tmp;
		i++;
	}
}

// assigns each number in stack an index
// i.e. 12-31-4-90-22 becomes 2-4-1-5-2
void	index_stack(t_stack *stack)
{
	int		i;
	int		j;
	int		size;
	int		*tmp;

	i = 0;
	j = 0;
	size = stack->size_a;
	tmp = ft_array_dup(stack->stack_a, size);
	insertion_sort(tmp, size);
	while (i < size)
	{
		while (j < size)
		{
			if (stack->stack_a[i] == tmp[j])
			{
				stack->stack_a[i] = j;
				break ;
			}
			j++;
		}
		j = 0;
		i++;
	}
	free(tmp);
}
