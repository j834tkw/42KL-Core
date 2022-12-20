/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutong <jutong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:35:23 by jutong            #+#    #+#             */
/*   Updated: 2022/12/08 13:50:33 by jutong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_actuallyprinthexptr(uintptr_t ptr, char *basehex)
{
	if (ptr >= 16)
		ft_actuallyprinthexptr((ptr / 16), basehex);
	write(1, &basehex[ptr % 16], 1);
}

int	ft_printptr(void *ptr)
{
	int			plen;
	uintptr_t	ptrtemp;

	ptrtemp = (uintptr_t)ptr;
	plen = 2;
	write(1, "0x", 2);
	if (ptr == NULL)
		plen += ft_printchar('0');
	else
	{
		while (ptrtemp > 0)
		{
			ptrtemp /= 16;
			plen++;
		}
		ft_actuallyprinthexptr((uintptr_t)ptr, "0123456789abcdef");
	}
	return (plen);
}
