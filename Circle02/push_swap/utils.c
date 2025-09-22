/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutong <jutong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 08:36:54 by jutong            #+#    #+#             */
/*   Updated: 2023/06/13 08:36:55 by jutong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	return ;
}

int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	*ft_array_dup(int *arr, int size)
{
	int		i;
	int		*dest;

	i = 0;
	dest = (int *) malloc(sizeof(int) * size);
	if (dest == 0)
		return (0);
	while (i < size)
	{
		dest[i] = arr[i];
		i++;
	}
	return (dest);
}
