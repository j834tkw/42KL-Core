/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutong <jutong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 08:34:50 by jutong            #+#    #+#             */
/*   Updated: 2023/06/13 08:34:53 by jutong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_stack *stack)
{
	int	i;
	int	size;

	i = 0;
	size = stack->size_a;
	while (i < size - 1)
	{
		if (stack->stack_a[i] > stack->stack_a[i + 1])
			return (0);
		i++;
	}
	if (stack->size_b != 0)
		return (0);
	return (1);
}

int	check_duplicate(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < stack->size_a)
	{
		j = 1;
		while (i + j < stack->size_a)
		{
			if (stack ->stack_a[i] == stack ->stack_a[i + j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_non_number(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (ft_isspace(str[i][j]) || str[i][j] == '+' || str[i][j] == '-')
			j++;
		while (str[i][j])
		{
			if (str[i][j] < '0' || str[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
