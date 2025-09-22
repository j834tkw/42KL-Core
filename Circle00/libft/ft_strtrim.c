/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutong <jutong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:24:34 by jutong            #+#    #+#             */
/*   Updated: 2022/10/11 13:24:34 by jutong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isinset(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;
	int		size;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	start = -1;
	size = ft_strlen(s1);
	end = size;
	while (ft_isinset(set, s1[++start]) == 1)
		size--;
	if (start != end)
	{
		while (ft_isinset(set, s1[--end]) == 1)
			size--;
		str = ft_substr(s1, start, size);
	}
	else
		str = ft_strdup("");
	if (str)
		return (str);
	return (0);
}
