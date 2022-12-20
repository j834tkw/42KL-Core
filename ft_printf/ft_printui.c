/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutong <jutong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:04:23 by jutong            #+#    #+#             */
/*   Updated: 2022/12/08 11:58:22 by jutong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_uitoa(unsigned int n)
{
	char				*str;
	int					digits;
	unsigned int		tmp;

	digits = 0;
	tmp = n;
	while (tmp >= 10)
	{
		tmp /= 10;
		digits++;
	}
	digits += 1;
	str = (char *)malloc((digits + 1) * sizeof(char));
	if (!str)
		return (0);
	str[digits] = '\0';
	while (--digits >= 0)
	{
		str[digits] = (char)((n % 10) + '0');
		n /= 10;
	}
	return (str);
}

int	ft_printui(unsigned int ui)
{
	int		plen;
	char	*str;

	plen = 0;
	if (ui == 0)
	{
		write(1, "0", 1);
		plen++;
	}
	else
	{
		str = ft_uitoa(ui);
		plen += ft_printstr(str);
		free(str);
	}
	return (plen);
}