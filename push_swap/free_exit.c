#include "push_swap.h"

void	free_and_exit(t_stack *stack, int to_print)
{
	if (stack->stack_a)
		free(stack->stack_a);
	if (stack->stack_b)
		free(stack->stack_b);
	if (to_print == 1)
		write(2, "Error\n", 6);
	if (to_print == 2)
		write(1, "OK\n", 3);
	if (to_print == 3)
		write(1, "KO\n", 3);
	exit (0);
}

void	free_and_exit_both(char **to_free, t_stack *to_free_2)
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
	free_and_exit(to_free_2, 1);
	exit (0);
}
