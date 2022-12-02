/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutong <jutong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 08:02:23 by jutong            #+#    #+#             */
/*   Updated: 2022/11/17 08:03:56 by jutong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*arr;

	if (nitems > 4294967295 || size > 4294967295)
		return (NULL);
	arr = (void *)malloc(nitems * size);
	if (!arr)
		return (NULL);
	ft_bzero(arr, nitems * size);
	return (arr);
}
