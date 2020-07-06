/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_types_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 12:52:19 by teva              #+#    #+#             */
/*   Updated: 2020/07/06 14:13:07 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static t_n_spec	second_part_of_nothing(va_list ap, int len,\
										t_flags flags, t_n_spec *n_spec)
{
	if (flags.l)
	{
		n_spec->li = va_arg(ap, long int*);
		*n_spec->li = len;
	}
	else if (flags.ll)
	{
		n_spec->lli = va_arg(ap, long long int *);
		*n_spec->lli = len;
	}
	return (*n_spec);
}

int				pf_nothing(va_list ap, int len, t_flags flags)
{
	t_n_spec n_spec;

	if (flags.h)
	{
		n_spec.si = (short int *)va_arg(ap, int*);
		*n_spec.si = len;
	}
	else if (flags.hh)
	{
		n_spec.sc = (signed char *)va_arg(ap, int*);
		*n_spec.sc = len;
	}
	if (flags.l || flags.ll)
		n_spec = second_part_of_nothing(ap, len, flags, &n_spec);
	else
	{
		n_spec.i = va_arg(ap, int *);
		*n_spec.i = len;
	}
	return (len);
}

char			*pf_floating_point(va_list ap, t_flags flags)
{
	double	dbl;
	char	*str;
	int		prec;

	dbl = flags.capital_l ? va_arg(ap, long double) : va_arg(ap, double);
	prec = pf_float_precision(flags);
	str = ft_dtoa(dbl, prec, 10);
	if (flags.pound && prec == 0)
		str = ft_strappend_change_first(&str, ".");
	return (str);
}

char			*pf_scientific_notation(va_list ap, char c, t_flags flags)
{
	char	*str;
	double	dbl;
	int		prec;
	int		ctr;

	dbl = flags.capital_l ? va_arg(ap, long double) : va_arg(ap, double);
	prec = pf_float_precision(flags);
	str = ft_dtosci(dbl, prec, flags);
	if (c == 'E' && (ctr = 0))
		while (str[ctr])
		{
			str[ctr] = ft_toupper(str[ctr]);
			ctr++;
		}
	return (str);
}

char			*pf_float_or_sci(va_list ap, char c, t_flags flags)
{
	char	*str_f;
	char	*str_e;
	double	dbl;
	int		prec;
	int		x;

	printf("\nstr_f address: %p\n", (void *)str_f);
	printf("str_e address: %p\n", (void *)str_e);
	dbl = flags.capital_l ? va_arg(ap, long double) : va_arg(ap, double);
	prec = pf_float_precision(flags);
	str_e = ft_dtosci_for_g(&x, dbl, prec - 1, flags);
	printf("\nstr_e value: %s\nstr_e address: %p\n", str_e, (void *)str_e);
	prec = prec - (x + 1);
	str_f = ft_dtoa_for_g(dbl, prec, 10);
	printf("str_f value: %s\nstr_f address: %p\n", str_f, (void *)str_f);
	printf("str_e value: %s\nstr_e address: %p\n", str_e, (void *)str_e);
	if (c == 'G' && (prec = 0))
		while (str_e[prec])
		{
			str_e[prec] = ft_toupper(str_e[prec]);
			prec++;
		}
	prec = pf_float_precision(flags);
	if (x >= -4 && prec > x)
		return (str_f);
	else
		return (str_e);
}
