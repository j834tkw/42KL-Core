#include "push_swap.h"

void	radix_sort(t_stack *stack)
{
	int	i;
	int	bitshift;
	int	size;

	bitshift = 0;
	size = stack->size_a;
	while (check_sorted(stack) == 0)
	{
		i = 0;
		while (i < size)
		{
			if (((stack->stack_a[0] >> bitshift) & 1) == 1)
				ra(stack, 1);
			else
				pb(stack, 1);
			i++;
		}
		while (stack->size_b > 0)
			pa(stack, 1);
		bitshift++;
	}
}