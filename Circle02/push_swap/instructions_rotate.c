/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutong <jutong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 08:36:11 by jutong            #+#    #+#             */
/*   Updated: 2023/06/13 08:36:13 by jutong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack, int to_print)
{
	int	i;

	if (stack->size_a <= 1)
		return ;
	i = 0;
	while (i < stack->size_a - 1)
	{
		ft_swap(&stack->stack_a[i], &stack->stack_a[i + 1]);
		i++;
	}
	if (to_print == 1)
		write(1, "ra\n", 3);
	stack->instruction_count++;
}

void	rb(t_stack *stack, int to_print)
{
	int	i;

	if (stack->size_b <= 1)
		return ;
	i = 0;
	while (i < stack->size_b - 1)
	{
		ft_swap(&stack->stack_b[i], &stack->stack_b[i + 1]);
		i++;
	}
	if (to_print == 1)
		write(1, "rb\n", 3);
	stack->instruction_count++;
}

void	rr(t_stack *stack, int to_print)
{
	ra(stack, 0);
	rb(stack, 0);
	if (to_print == 1)
		write(1, "rr\n", 3);
	stack->instruction_count++;
}
