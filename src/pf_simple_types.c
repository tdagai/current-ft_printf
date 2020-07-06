/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_simple_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 09:09:46 by teva              #+#    #+#             */
/*   Updated: 2020/06/25 16:45:02 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		pf_char(va_list ap, t_flags *flags)
{
	int		i;
	char	*str;

	i = (char)va_arg(ap, int);
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

char	*pf_int(va_list ap)
{
	int		i;
	char	*str;

	i = va_arg(ap, int);
	str = ft_itoa_base((long long int)i, 10);
	return (str);
}

char	*pf_str(va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	return (str);
}

char	*pf_ui(va_list ap)
{
	unsigned int	ui;
	char			*str;

	ui = va_arg(ap, unsigned int);
	str = ft_itoa_base_unsigned((unsigned long long int)ui, 10);
	return (str);
}
