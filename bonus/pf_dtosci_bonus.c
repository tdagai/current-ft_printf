/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_dtosci_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 15:56:17 by teva              #+#    #+#             */
/*   Updated: 2020/07/06 14:34:38 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char		*what_to_fix(char *fix, int exponent, int prec, t_flags flags)
{
	fix = ft_strnew(1);
	if (flags.pound && prec == 0)
	{
		fix[0] = '.';
		fix = ft_strappend_change_first(&fix, "e");
	}
	else
		fix[0] = 'e';
	if (exponent < 0)
		fix = ft_strappend_change_first(&fix, "-");
	else
		fix = ft_strappend_change_first(&fix, "+");
	exponent < 10 && exponent >= 0 ?\
	fix = ft_strappend_change_first(&fix, "0") : 0;
	exponent > -10 && exponent < 0 ?\
		fix = ft_strappend_change_first(&fix, "0") : 0;
	fix = ft_strappend_change_first(&fix, ft_itoa_base(ft_abs(exponent), 10));
	return (fix);
}

char			*ft_dtosci(long double dbl, int prec, t_flags flags)
{
	long double	nb;
	int			exponent;
	char		*ret;
	char		*fix;

	nb = ft_abs_dbl(dbl);
	exponent = 0;
	if (nb >= 10 && nb > 1)
		while (nb >= 10 && (++exponent))
			nb /= 10;
	else if (nb < 1 && nb > 0)
		while (nb < 1 && (--exponent))
			nb *= 10;
	ft_round_digits(nb, prec) >= 10 && (exponent += 1) ? nb /= 10 : 0;
	ft_signbit(dbl) ? nb = -nb : 0;
	ret = ft_dtoa(nb, prec, 10);
	!ft_signbit(dbl) && flags.plus ? ft_strappend_change_second("+", &ret) : 0;
	!ft_signbit(dbl) && flags.space ? ft_strappend_change_second(" ", &ret) : 0;
	fix = NULL;
	fix = what_to_fix(fix, exponent, prec, flags);
	ret = ft_strappend_change_second(ret, &fix);
	ft_strdel(&fix);
	return (ret);
}

char			*ft_dtosci_for_g(int *exponent, long double dbl,\
				int prec, t_flags flags)
{
	long double	nb;
	char		*fix;
	char		*str;

	printf("\n+++str value: %s\n+++str address: %p\n", str, (void *)str);
	str = ft_strnew(1);
	nb = ft_abs_dbl(dbl);
	*exponent = 0;
	if (nb >= 10 && nb > 1)
		while (nb >= 10 && (++(*exponent)))
			nb /= 10;
	else if (nb < 1 && nb > 0)
		while (nb < 1 && (--(*exponent)))
			nb *= 10;
	ft_round_digits(nb, prec) >= 10 && (*exponent += 1) ? nb /= 10 : 0;
	ft_signbit(dbl) ? nb = -nb : 0;
	printf("+++str value: %s\n+++str address: %p\n", str, (void *)str);
	str = ft_dtoa_for_g(nb, prec, 10);
	printf("+++str value: %s\n+++str address: %p\n", str, (void *)str);
	!ft_signbit(dbl) && flags.plus ? ft_strappend_change_second("+", &str) : 0;
	if (!ft_signbit(dbl) && flags.space)
		ft_strappend_change_second(" ", &str);
	fix = NULL;
	fix = what_to_fix(fix, *exponent, prec, flags);
	str = ft_strappend_change_second(str, &fix);
	printf("+++str value: %s\n+++str address: %p\n", str, (void *)str);
	ft_strdel(&fix);
	int ctr = 0;
	while (str[ctr])
	{
		printf("%c\n", str[ctr++]);
	}
	return (str);
}

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

char	*ft_dtoa_for_g(long double dbl, size_t prec, int base)
{
	long double	nb;
	size_t		len;
	size_t		exp;
	char		*str1;
	char		*str2;
	char		*temp;

	str1 = ft_strnew(1);
	printf("\n***str1 value: %s\n***str1 address: %p\n", str1, (void *)str1);
	nb = (dbl < 0) ? ft_round_digits(-dbl, prec) : ft_round_digits(dbl, prec);
	str1 = ft_itoa_base_unsigned((unsigned long long int)nb, base);
	printf("***str1 value: %s\n***str1 address: %p\n", str1, (void *)str1);
	nb = (dbl < 0) ? ft_round_rval((dbl - (long long int)dbl) * -1,\
			prec) : ft_round_rval(dbl - (unsigned long long int)dbl, prec);
	exp = find_exponent(nb);
	nb *= ft_pow(base, prec);
	while ((long long int)nb != 0 && (unsigned long long int)nb % 10 == 0)
		nb /= 10;
	str2 = ft_itoa_base_unsigned((unsigned long long int)nb, base);
	printf("***str2 value: %s\n***str2 address: %p\n", str2, (void *)str2);
	if ((len = ft_strlen(str2)) < exp)
	while (len++ <= exp)
		ft_strappend_change_second("0", &str2);
	prec > 0 && prec < ft_strlen(str2) ? (str2 = ft_downsize(str2, prec)) : 0;
	ft_signbit(dbl) && base == 10 ? ft_strappend_change_second("-", &str1) : 0;
	printf("***str2 value: %s\n***str2 address: %p\n", str2, (void *)str2);
	if (prec > 0 && base == 10 && (long long int)nb != 0)
	{
		ft_strappend_change_first(&str1, ".");
		ft_strappend_change_first(&str1, str2);
	}
	printf("***str1 value: %s\n***str1 address: %p\n", str1, (void *)str1);
	ft_strdel(&str2);
	printf("***str2 value: %s\n***str2 address: %p\n", str2, (void *)str2);
	temp = ft_strnew(ft_strlen(str1));
	temp = ft_strcpy(temp, str1);
	printf("***temp value: %s\n***temp address: %p\n", temp, (void *)temp);
	ft_strdel(&str1);
	printf("***str1 value: %s\n***str1 address: %p\n", str1, (void *)str1);
	return (temp);
}
