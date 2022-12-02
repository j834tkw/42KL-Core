/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutong <jutong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:44:05 by jutong            #+#    #+#             */
/*   Updated: 2022/11/17 08:28:03 by jutong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	destlen;
	size_t	srclen;
	size_t	i;
	int		j;

	if (dest == NULL && size == 0)
		return (ft_strlen((char *)src));
	destlen = ft_strlen(dest);
	srclen = ft_strlen((char *)src);
	if (size == 0 || destlen > size)
		return (size + srclen);
	i = destlen;
	j = 0;
	if (destlen < size - 1 && size > 0)
	{
		while (src[j] != '\0' && i < (size - 1))
			dest[i++] = src[j++];
		dest[i] = '\0';
	}
	return (destlen + srclen);
}
