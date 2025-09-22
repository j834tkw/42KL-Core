/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:30:39 by jteoh             #+#    #+#             */
/*   Updated: 2024/01/10 17:44:24 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms.h"

void	get_flag(int *flag, char c, int pos)
{
	if (c == '\"')
	{
		if (flag[0] % 2 == 0)
			flag[1] = pos;
		flag[0]++;
	}
	else if (c == '\'')
	{
		if (flag[2] % 2 == 0)
			flag[3] = pos;
		flag[2]++;
	}
}

int	analyze_flag(int *flag, char here, char there)
{
	if (here == '$' && (there == '\'' || there == '\"'))
	{
		if (flag[0] % 2 == 1 || flag[2] % 2 == 1)
			return (0);
	}
	if (flag[0] % 2 == 0 && flag[2] % 2 == 0)
		return (1);
	else if (flag[0] % 2 == 1 && flag[2] % 2 == 0)
		return (1);
	else if (flag[0] % 2 == 0 && flag[2] % 2 == 1)
		return (0);
	else if (flag[0] % 2 == 1 && flag[2] % 2 == 1)
	{
		if (flag[3] < flag[1])
			return (0);
		if (flag[1] < flag[3])
			return (1);
	}
	return (0);
}

int	analyze_flag_2(int *flag)
{
	if (flag[0] % 2 == 0 && flag[2] % 2 == 0)
		return (1);
	else if (flag[0] % 2 == 1 && flag[2] % 2 == 0)
	{
		if (flag[1] < flag[3])
			return (2);
	}
	else if (flag[0] % 2 == 0 && flag[2] % 2 == 1)
	{
		if (flag[1] > flag[3])
			return (3);
	}
	else if (flag[0] % 2 == 1 && flag[2] % 2 == 1)
	{
		if (flag[1] < flag[3])
			return (4);
		else
			return (5);
	}
	return (0);
}
