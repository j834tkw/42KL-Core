#include "push_swap.h"

void	sa(t_stack *stack, int to_print)
{
	if (stack->size_a <= 1)
		return ;
	ft_swap(&stack->stack_a[0], &stack->stack_a[1]);
	if (to_print == 1)
		write(1, "sa\n", 3);
	stack->instruction_count++;
}

void	sb(t_stack *stack, int to_print)
{
	if (stack->size_b <= 1)
		return ;
	ft_swap(&stack->stack_b[0], &stack->stack_b[1]);
	if (to_print == 1)
		write(1, "sb\n", 3);
	stack->instruction_count++;
}

void	ss(t_stack *stack, int to_print)
{
	sa(stack, 0);
	sb(stack, 0);
	if (to_print == 1)
		write(1, "ss\n", 3);
	stack->instruction_count++;
}
