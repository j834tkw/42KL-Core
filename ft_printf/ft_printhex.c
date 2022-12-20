/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutong <jutong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:30:33 by jutong            #+#    #+#             */
/*   Updated: 2022/12/14 10:28:59 by jutong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_actuallyprinthex(unsigned int n, char *basehex)
{
	if (n >= 16)
		ft_actuallyprinthex((n / 16), basehex);
	write(1, &basehex[n % 16], 1);
}

int	ft_printhex(unsigned int n, char *basehex)
{
	int				plen;
	unsigned int	ntemp;

	plen = 0;
	ntemp = n;
	if (n == 0)
	{
		plen += ft_printchar('0');
		return (plen);
	}
	while (ntemp > 0)
	{
		ntemp /= 16;
		plen++;
	}
	ft_actuallyprinthex(n, basehex);
	return (plen);
}
