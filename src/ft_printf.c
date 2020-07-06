/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 12:09:34 by teva              #+#    #+#             */
/*   Updated: 2020/06/25 16:43:59 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		format_specifiers(char c, va_list ap, t_flags flags)
{
	int		len;
	char	*str;

	len = 0;
	str = NULL;
	if (c == 'c')
		return (pf_char(ap, &flags));
	else if (c == 'i' || c == 'd')
		str = pf_int(ap);
	else if (c == 's')
		str = pf_str(ap);
	else if (c == 'u')
		str = pf_ui(ap);
	else if (c == 'p')
		str = pf_ptraddr(ap);
	else if (c == 'x' || c == 'X')
		str = pf_hex(ap, c);
	else if (c == '%')
		str = "%";
	else
		return (ft_putstr(""));
	len = pf_work_with_flags(str, c, flags);
	return (len);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*traverse;
	int			len;
	t_flags		flags;

	va_start(ap, format);
	traverse = (char *)format;
	len = 0;
	while (*traverse)
	{
		flags = flags_init();
		if (*traverse == '%' && *(traverse + 1) != 0)
		{
			traverse++;
			if (is_flag(*traverse))
				traverse = parse_flags(traverse, ap, &flags);
			len += format_specifiers(*traverse, ap, flags);
			if (*traverse == '\0')
				break ;
		}
		else
		{
			ft_putchar(*traverse);
			len += 1;
		}
		traverse++;
	}
	va_end(ap);
	return (len);
}
