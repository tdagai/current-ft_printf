/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 13:57:06 by teva              #+#    #+#             */
/*   Updated: 2020/07/03 12:53:32 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dtoa(long double dbl, size_t prec, int base)
{
	long double	nb;
	char		*str1;
	char		*str2;

	nb = (dbl < 0) ? ft_round_digits(-dbl, prec) : ft_round_digits(dbl, prec);
	str1 = ft_itoa_base_unsigned((unsigned long long int)nb, base);
	nb = (dbl < 0) ? ft_round_rval((dbl - (long long int)dbl) * -1,\
			prec) : ft_round_rval(dbl - (unsigned long long int)dbl, prec);
	nb *= ft_pow(base, prec);
	str2 = ft_itoa_base_unsigned((unsigned long long int)nb, base);
	if ((nb = ft_strlen(str2)) < prec)
		while (nb++ < prec)
			ft_strappend_change_second("0", &str2);
	if (prec > 0 && prec < (nb = ft_strlen(str2)))
		str2 = ft_downsize(str2, prec);
	ft_signbit(dbl) && base == 10 ? ft_strappend_change_second("-", &str1) : 0;
	if (prec > 0 && base == 10)
	{
		ft_strappend_change_first(&str1, ".");
		ft_strappend_change_first(&str1, str2);
	}
	ft_strdel(&str2);
	return (str1);
}
/*
static int	find_exponent(long double dbl)
{
	int	exponent;

	exponent = 0;
	if (dbl == 0)
		return (0);
	while (dbl < 1)
	{
		dbl *= 10;
		exponent++;
	}
	return (exponent);
}

char	*ft_dtoa_for_g(char **str1, long double dbl, size_t prec, int base)
{
	long double	nb;
	size_t		len;
	size_t		exp;
	char		*str2;

	nb = (dbl < 0) ? ft_round_digits(-dbl, prec) : ft_round_digits(dbl, prec);
	*str1 = ft_itoa_base_unsigned((unsigned long long int)nb, base);
	nb = (dbl < 0) ? ft_round_rval((dbl - (long long int)dbl) * -1,\
			prec) : ft_round_rval(dbl - (unsigned long long int)dbl, prec);
	exp = find_exponent(nb);
	nb *= ft_pow(base, prec);
	while ((long long int)nb != 0 && (unsigned long long int)nb % 10 == 0)
		nb /= 10;
	str2 = ft_itoa_base_unsigned((unsigned long long int)nb, base);
	if ((len = ft_strlen(str2)) < exp)
	while (len++ <= exp)
		ft_strappend_change_second("0", &str2);
	prec > 0 && prec < ft_strlen(str2) ? (str2 = ft_downsize(str2, prec)) : 0;
	ft_signbit(dbl) && base == 10 ? ft_strappend_change_second("-", str1) : 0;
	if (prec > 0 && base == 10 && (long long int)nb != 0)
	{
		ft_strappend_change_first(str1, ".");
		ft_strappend_change_first(str1, str2);
	}
	ft_strdel(&str2);
	return (*str1);
}*/
