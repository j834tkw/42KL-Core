/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutong <jutong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:11:56 by jutong            #+#    #+#             */
/*   Updated: 2023/07/10 17:14:46 by jutong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(char *s1)
{
	char	*s2;
	int		i;

	s2 = (char *)malloc(ft_strlen((char *)s1) + 1);
	if (!s2)
		return (0);
	i = 0;
	while ((char)s1[i] != '\0')
	{
		s2[i] = (char)s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}
