/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutong <jutong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:08:19 by jutong            #+#    #+#             */
/*   Updated: 2023/07/10 17:08:22 by jutong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;

	i = 0;
	if (size > 0)
	{
		while (i < (size - 1) && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	srclen = ft_strlen(src);
	return (srclen);
}

int	ft_countwords(char const *s, char c)
{
	int	words;
	int	i;
	int	nocount;

	i = 0;
	words = 0;
	nocount = 0;
	while (s[i])
	{
		if (s[i] != c && nocount == 0)
		{
			words++;
			nocount = 1;
		}
		if (s[i] == c)
			nocount = 0;
		i++;
	}
	return (words);
}

size_t	ft_delimstrl(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	count = ft_countwords(s, c);
	str = malloc((count + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (i < ft_strlen((char *)s) && j < count)
	{
		while (!ft_delimstrl(s + i, c))
			i++;
		str[j] = malloc((ft_delimstrl(s + i, c) + 1) * sizeof(char));
		if (!str)
			return (NULL);
		ft_strlcpy(str[j++], s + i, ft_delimstrl(s + i, c) + 1);
		i += ft_delimstrl(s + i, c) + 1;
	}
	str[j] = NULL;
	return (str);
}
