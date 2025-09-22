/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutong <jutong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 08:17:28 by jutong            #+#    #+#             */
/*   Updated: 2022/10/31 15:58:38 by jutong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*arr;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s);
	arr = (char *)malloc((len + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	while (s[i])
	{
		arr[i] = s[i];
		i++;
	}
	arr[i] = 0;
	return (arr);
}
