/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdagai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:16:56 by tdagai            #+#    #+#             */
/*   Updated: 2020/02/25 10:58:13 by tdagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	long_while(char *str, int start)
{
	return ((str[start] == ' ' || str[start] == '\n' || str[start] == '\t' ||
			str[start] == '\r' || str[start] == '\v' || str[start] == '\f') &&
			str[start] != '\0');
}

static int	long_loop(char *str, int ctr, int start)
{
	return ((((str[ctr] == '+' || str[ctr] == '-') && ctr == start) ||
		(str[ctr] >= '0' && str[ctr] <= '9')) && str[ctr] != '\0');
}

int			ft_atoi(char *str)
{
	int ctr;
	int start;
	int to_convert;
	int sign;

	start = 0;
	while (long_while(str, start))
		start++;
	ctr = start;
	to_convert = 0;
	sign = 1;
	while (long_loop(str, ctr, start))
	{
		if (str[ctr] == '-')
			sign = -1;
		if (str[ctr] >= '0' && str[ctr] <= '9')
		{
			to_convert *= 10;
			to_convert += (str[ctr] - '0');
		}
		ctr++;
	}
	return (to_convert * sign);
}
