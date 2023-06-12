#include "push_swap.h"
#include "./gnl/get_next_line.h"

int	ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (-1);
		i++;
	}
	return (0);
}

void	check_compare(char *instr, t_stack *stack)
{
	if (!ft_strcmp(instr, "sa\n"))
		sa(stack, 0);
	else if (!ft_strcmp(instr, "sb\n"))
		sb(stack, 0);
	else if (!ft_strcmp(instr, "ss\n"))
		ss(stack, 0);
	else if (!ft_strcmp(instr, "pa\n"))
		pa(stack, 0);
	else if (!ft_strcmp(instr, "pb\n"))
		pb(stack, 0);
	else if (!ft_strcmp(instr, "ra\n"))
		ra(stack, 0);
	else if (!ft_strcmp(instr, "rb\n"))
		rb(stack, 0);
	else if (!ft_strcmp(instr, "rr\n"))
		rr(stack, 0);
	else if (!ft_strcmp(instr, "rra\n"))
		rra(stack, 0);
	else if (!ft_strcmp(instr, "rrb\n"))
		rrb(stack, 0);
	else if (!ft_strcmp(instr, "rrr\n"))
		rrr(stack, 0);
	else
		free_and_exit(stack, 1);
}

void checker(t_stack *stack)
{
	char	*read;

	while (1)
	{
		read = get_next_line(0);
		if (read == NULL || !ft_strcmp("\n", read))
			break ;
		check_compare(read, stack);
		if (read)
			free (read);
	}
	if (read)
			free(read);
	if (check_sorted(stack) == 1)
		free_and_exit(stack, 2);
	else if (check_sorted(stack) == 0)
		free_and_exit(stack, 3);
}

int	main(int ac, char **av)
{
	t_stack	stack;

	if (ac < 2)
		return (0);
	ft_initialize_struct(&stack);
	ft_fill_data(&stack, ac, av);
	if (check_duplicate(&stack) == 0)
		free_and_exit(&stack, 1);
	if (check_sorted(&stack) == 1)
		free_and_exit(&stack, 0);
	checker(&stack);
	return (0);
}
