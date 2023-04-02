#include "push_swap.h"

void	free_and_exit(t_stack *stack, int to_print)
{
	if (stack->stack_a)
		free(stack->stack_a);
	if (stack->stack_b)
		free(stack->stack_b);
	free(stack);
	if (to_print == 1)
		write(2, "Error\n", 6);
	exit (0);
}

void	free_and_exit_but_chardp(char **to_free)
{
	int	i;

	i = 0;
	if (to_free)
	{
		while (to_free[i])
		{
			free(to_free[i]);
			i++;
		}
	}
	free(to_free);
	write(2, "Error\n", 6);
	exit (0);
}