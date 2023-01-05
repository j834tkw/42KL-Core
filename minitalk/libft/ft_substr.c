/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutong <jutong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 08:31:25 by jutong            #+#    #+#             */
/*   Updated: 2022/12/02 08:53:19 by jutong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkmalloc(char const *s, int start, int len)
{
	int	mlen;

	if (len - start > (int)ft_strlen(s) - start)
		mlen = ft_strlen(s) - start;
	else
		mlen = len;
	return (mlen);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;
	int		mlen;
	int		j;

	if (!s)
		return (NULL);
	if (!len || start > (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	i = 0;
	j = 0;
	mlen = ft_checkmalloc(s, (int)start, (int)len);
	str = (char *)malloc((mlen + 1) * sizeof(*s));
	if (!str)
		return (NULL);
	while (s[i])
	{
		if (i >= (int)start && j < (int)len)
			str[j++] = s[i];
		i++;
	}
	str[j] = '\0';
	return (str);
}
