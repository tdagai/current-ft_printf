/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 15:57:54 by teva              #+#    #+#             */
/*   Updated: 2020/06/22 13:58:39 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double		ft_abs_dbl(long double dbl)
{
	if (ft_signbit(dbl))
		return (dbl * -1);
	return (dbl);
}

long long int	ft_abs(long long int lli)
{
	if (lli < 0)
		return (lli * -1);
	return (lli);
}
