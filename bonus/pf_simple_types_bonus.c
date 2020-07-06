/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_simple_types_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 09:09:46 by teva              #+#    #+#             */
/*   Updated: 2020/06/24 18:06:16 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int		pf_char(va_list ap, t_flags *flags)
{
	int		i;
	char	*str;

	i = flags->l ? va_arg(ap, wint_t) : va_arg(ap, int);
	if (i == '\0')
	{
		flags->null = 1;
		return (if_null_char((char)i, *flags));
	}
	else
	{
		str = ft_strnew(1);
		str[0] = i;
		str[1] = '\0';
		i = pf_work_with_flags(str, 'c', *flags);
		ft_strdel(&str);
		return (i);
	}
}

int		if_null_char(char i, t_flags flags)
{
	int		width;
	int		ctr;

	width = pf_determine_width_char(flags);
	ctr = 0;
	if (flags.dash)
	{
		ft_putchar(i);
		while (ctr++ < width - 1)
			ft_putchar(32);
	}
	else
	{
		while (ctr++ < width - 1)
			ft_putchar(32);
		ft_putchar(i);
	}
	return (width);
}

char	*pf_int(va_list ap, t_flags flags)
{
	int		i;
	char	*str;

	if (flags.h)
		i = (short int)va_arg(ap, int);
	else if (flags.hh)
		i = (signed char)va_arg(ap, int);
	else if (flags.l)
		i = va_arg(ap, long int);
	else if (flags.ll)
		i = va_arg(ap, long long int);
	else
		i = va_arg(ap, int);
	str = ft_itoa_base((long long int)i, 10);
	return (str);
}

char	*pf_str(va_list ap, t_flags flags)
{
	char	*str;

	str = flags.l ? (char *)va_arg(ap, wchar_t *) : va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	return (str);
}

char	*pf_ui(va_list ap, t_flags flags)
{
	unsigned int	ui;
	char			*str;

	if (flags.h)
		ui = (unsigned short int)va_arg(ap, unsigned int);
	else if (flags.hh)
		ui = (unsigned char)va_arg(ap, unsigned int);
	else if (flags.l)
		ui = va_arg(ap, unsigned long int);
	else if (flags.ll)
		ui = va_arg(ap, unsigned long long int);
	else
		ui = va_arg(ap, unsigned int);
	str = ft_itoa_base_unsigned((unsigned long long int)ui, 10);
	return (str);
}
