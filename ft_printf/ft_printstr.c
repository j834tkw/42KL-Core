/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutong <jutong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:26:05 by jutong            #+#    #+#             */
/*   Updated: 2022/12/14 10:29:11 by jutong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *str)
{
	int	strlen;

	strlen = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[strlen] != '\0')
		strlen++;
	write(1, str, strlen);
	return (strlen);
}