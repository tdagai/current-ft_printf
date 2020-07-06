/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 16:23:47 by teva              #+#    #+#             */
/*   Updated: 2020/06/24 14:05:35 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digits_in_num(long long int i)
{
	int ctr;

	ctr = 0;
	while (i > 0)
	{
		ctr++;
		i /= 10;
	}
	return (ctr);
}

long double	ft_round_digits(long double dbl, int precision)
{
	long double	pwr;

	pwr = ft_pow(10, precision + 1);
	dbl *= pwr;
	if ((long long int)dbl % 10 < 5)
		return (dbl / pwr);
	dbl += 10;
	return (dbl / pwr);
}

long double	ft_round_rval(long double dbl, int precision)
{
	long double	pwr;
	int			digits_before;
	int			digits_after;

	pwr = ft_pow(10, precision + 1);
	dbl *= pwr;
	if ((long long int)dbl % 10 < 5)
		return (dbl / pwr);
	digits_before = digits_in_num((long long int)dbl);
	dbl += 10;
	digits_after = digits_in_num((long long int)dbl);
	if (digits_after > digits_before && digits_after > precision)
		return (0);
	else
		return (dbl / pwr);
}

int			ft_left_of_dot(long double dbl)
{
	int ctr;

	if ((int)dbl == 0)
		return (1);
	ctr = 0;
	while ((int)dbl > 0)
	{
		dbl /= 10;
		ctr++;
	}
	return (ctr);
}
