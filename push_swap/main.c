#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack stack;

	if (ac < 2 || !check_non_number(av))
		return (0);
	ft_initialize_struct(&stack);
	ft_fill_data(&stack, ac, av);
	if (check_duplicate(&stack) == 0)
		free_and_exit(&stack, 1);
	if (check_sorted(&stack) == 1)
		free_and_exit(&stack, 0);
	ft_push_swap(&stack);
	free_and_exit(&stack, 0);
	return (0);
}

void ft_push_swap(t_stack *stack)
{
	index_stack(stack);
	if (stack->size_a == 2)
		sort_2(stack);
	else if (stack->size_a == 3)
		sort_3(stack);
	else if (stack->size_a == 4 || stack->size_a == 5)
		sort_5(stack);
	else if (stack->size_a > 5)
		radix_sort(stack);
}