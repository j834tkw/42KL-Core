/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutong <jutong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 01:25:47 by jutong            #+#    #+#             */
/*   Updated: 2022/12/08 12:50:32 by jutong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

int	ft_printf(const char *str, ...);

int	ft_printchar(int n);

int	ft_printhex(unsigned int n, char *basehex);

int	ft_printint(int n);

int	ft_printptr(void *ptr);

int	ft_printstr(char *str);

int	ft_printui(unsigned int ui);

#endif