/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 12:09:34 by teva              #+#    #+#             */
/*   Updated: 2020/06/28 09:33:42 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int		format_specifiers(char c, int len, va_list ap, t_flags flags)
{
	char	*str;

	str = NULL;
	if (c == 'c')
		return (pf_char(ap, &flags));
	else if (c == 'i' || c == 'd')
		str = pf_int(ap, flags);
	else if (c == 's')
		str = pf_str(ap, flags);
	else if (c == 'u')
		str = pf_ui(ap, flags);
	else if (c == 'p')
		str = pf_ptraddr(ap);
	else if (c == 'x' || c == 'X')
		str = pf_hex(ap, c, flags);
	else if (c == '%')
		str = "%";
	else if (c == 'n')
		return (pf_nothing(ap, len, flags));
	else if (c == 'f')
		str = pf_floating_point(ap, flags);
	else if (c == 'e' || c == 'E')
		str = pf_scientific_notation(ap, c, flags);
	else if (c == 'g' || c == 'G')
		str = pf_float_or_sci(ap, c, flags);
	else
		return (ft_putstr(""));
	len += pf_work_with_flags(str, c, flags);
	return (len);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*trav;
	int			len;
	t_flags		flags;

	va_start(ap, format);
	trav = (char *)format;
	len = 0;
	while (*trav)
	{
		(flags = flags_init());
		if (*trav == '%' && *(trav + 1) != 0)
		{
			trav++;
			is_flag(*trav) ? (trav = parse_flags(trav, ap, &flags)) : 0;
			len = format_specifiers(*trav, len, ap, flags);
			if(*trav == '\0')
				break ;
		}
		else
		{
			ft_putchar(*trav);
			len += 1;
		}
		trav++;
	}
	va_end(ap);
	return (len);
}
