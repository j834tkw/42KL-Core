/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rev_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutong <jutong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 08:36:04 by jutong            #+#    #+#             */
/*   Updated: 2023/06/13 11:27:22 by jutong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack, int to_print)
{
	int	i;

	if (stack->size_a <= 1)
		return ;
	i = stack->size_a - 1;
	while (i > 0)
	{
		ft_swap(&stack->stack_a[i], &stack->stack_a[i - 1]);
		i--;
	}
	if (to_print == 1)
		write(1, "rra\n", 4);
	stack->instruction_count++;
}

void	rrb(t_stack *stack, int to_print)
{
	int	i;

	if (stack->size_b <= 1)
		return ;
	i = stack->size_b - 1;
	while (i > 0)
	{
		ft_swap(&stack->stack_b[i], &stack->stack_b[i - 1]);
		i--;
	}
	if (to_print == 1)
		write(1, "rrb\n", 4);
	stack->instruction_count++;
}

void	rrr(t_stack *stack, int to_print)
{
	rra(stack, 0);
	rrb(stack, 0);
	if (to_print == 1)
		write(1, "rrr\n", 4);
	stack->instruction_count++;
}
