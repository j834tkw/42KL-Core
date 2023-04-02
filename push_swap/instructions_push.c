#include "push_swap.h"

void	ft_pa_move(t_stack *stack)
{
	int	i;

	i = stack->size_a;
	while (i > 0)
	{
		ft_swap(&stack->stack_a[i], &stack->stack_a[i - 1]);
		i--;
	}
	stack->stack_a[0] = stack->stack_b[0];
	i = 0;
	while (i < stack->size_b - 1)
	{
		ft_swap(&stack->stack_b[i], &stack->stack_b[i + 1]);
		i++;
	}
}

void	pa(t_stack *stack, int to_print)
{
	if (stack->size_b == 0)
		return ;
	ft_pa_move(stack);
	stack->size_a += 1;
	stack->size_b -= 1;
	if (to_print == 1)
		write(1, "pa\n", 3);
	stack->instruction_count++;
}

void	ft_pb_move(t_stack *stack)
{
	int	i;

	i = stack->size_b;
	while (i > 0)
	{
		ft_swap(&stack->stack_b[i], &stack->stack_b[i - 1]);
		i--;
	}
	stack->stack_b[0] = stack->stack_a[0];
	i = 0;
	while (i < stack->size_a - 1)
	{
		ft_swap(&stack->stack_a[i], &stack->stack_a[i + 1]);
		i++;
	}
}

void	pb(t_stack *stack, int to_print)
{
	if (stack->size_a == 0)
		return ;
	ft_pb_move(stack);
	stack->size_a -= 1;
	stack->size_b += 1;
	if (to_print == 1)
		write(1, "pb\n", 3);
	stack->instruction_count++;
}
