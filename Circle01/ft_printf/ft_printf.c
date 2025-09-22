/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutong <jutong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 00:54:59 by jutong            #+#    #+#             */
/*   Updated: 2022/12/14 10:35:40 by jutong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, const char format)
{
	int	plen;

	plen = 0;
	if (format == 'c')
		plen += ft_printchar(va_arg(args, int));
	else if (format == 's')
		plen += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		plen += ft_printptr(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		plen += ft_printint(va_arg(args, int));
	else if (format == 'u')
		plen += ft_printui(va_arg(args, unsigned int));
	else if (format == 'x')
		plen += ft_printhex(va_arg(args, unsigned int), "0123456789abcdef");
	else if (format == 'X')
		plen += ft_printhex(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (format == '%')
		plen += ft_printchar('%');
	return (plen);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		num;
	va_list	args;

	i = 0;
	num = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
			num += ft_printchar(str[i]);
		else if (str[i] == '%')
		{
			num += ft_format(args, str[i + 1]);
			i++;
		}
		i++;
	}
	va_end(args);
	return (num);
}
