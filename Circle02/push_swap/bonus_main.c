/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutong <jutong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 08:34:45 by jutong            #+#    #+#             */
/*   Updated: 2023/06/13 13:18:39 by jutong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./gnl/get_next_line.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (1);
		if (s1[i] == '\0' || s2[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

void	check_compare(char *instr, t_stack *stack)
{
	if (!ft_strncmp(instr, "sa\n", 3))
		sa(stack, 0);
	else if (!ft_strncmp(instr, "sb\n", 3))
		sb(stack, 0);
	else if (!ft_strncmp(instr, "ss\n", 3))
		ss(stack, 0);
	else if (!ft_strncmp(instr, "pa\n", 3))
		pa(stack, 0);
	else if (!ft_strncmp(instr, "pb\n", 3))
		pb(stack, 0);
	else if (!ft_strncmp(instr, "ra\n", 3))
		ra(stack, 0);
	else if (!ft_strncmp(instr, "rb\n", 3))
		rb(stack, 0);
	else if (!ft_strncmp(instr, "rr\n", 3))
		rr(stack, 0);
	else if (!ft_strncmp(instr, "rra\n", 4))
		rra(stack, 0);
	else if (!ft_strncmp(instr, "rrb\n", 4))
		rrb(stack, 0);
	else if (!ft_strncmp(instr, "rrr\n", 4))
		rrr(stack, 0);
	else
		free_and_exit(stack, 1);
}

void	checker(t_stack *stack)
{
	char	*read;

	while (1)
	{
		read = get_next_line(0);
		if (read == NULL)
			break ;
		check_compare(read, stack);
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
