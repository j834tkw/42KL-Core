#include "push_swap.h"

void	sort_2(t_stack *stack)
{
	if (stack->stack_a[0] > stack->stack_a[1])
		sa(stack, 1);
}

void	sort_3(t_stack *stack)
{
	int	*a;

	a = stack->stack_a;
	if (a[1] < a[2] && a[2] < a[0])
		ra(stack, 1);
	else if (a[1] < a[0] && a[2] < a[1])
	{
		sa(stack, 1);
		rra(stack, 1);
	}
	else if (a[2] < a[0] && a[0] < a[1])
		rra(stack, 1);
	else if (a[0] < a[2] && a[1] < a[0])
		sa(stack, 1);
	else if (a[0] < a[2] && a[2] < a[1])
	{
		rra(stack, 1);
		sa(stack, 1);
	}
}

// if stack_a has 4 numbers, do not pb 2nd smallest number
// Only do it if stack_a has 5 numbers
void	sort_5(t_stack *stack)
{
	int	original_size;

	original_size = stack->size_a;
	while (stack->size_a > 3)
	{
		if (stack->stack_a[0] == 0 || (original_size == 5 && stack->stack_a[0] == 1))
			pb(stack, 1);
		else
			ra(stack, 1);
	}
	if (stack->stack_b[0] < stack->stack_b[1])
		sb(stack, 1);
	sort_3(stack);
	pa(stack, 1);
	pa(stack, 1);
}
