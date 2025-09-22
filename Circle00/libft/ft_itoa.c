/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutong <jutong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 08:27:55 by jutong            #+#    #+#             */
/*   Updated: 2022/11/17 08:10:58 by jutong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoaneg(unsigned int n)
{
	char			*str;
	int				digits;
	unsigned int	tmp;

	digits = 1;
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
	str[0] = '-';
	str[digits] = '\0';
	while (--digits > 0)
	{
		str[digits] = (char)((n % 10) + '0');
		n /= 10;
	}
	return (str);
}

char	*ft_itoapos(int n)
{
	char	*str;
	int		digits;
	int		tmp;

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

char	*ft_itoa(int n)
{
	if (n < 0)
		return (ft_itoaneg((unsigned int)(n * -1)));
	return (ft_itoapos(n));
}
