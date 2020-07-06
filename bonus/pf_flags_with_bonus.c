/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_flags_with_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 10:28:22 by teva              #+#    #+#             */
/*   Updated: 2020/06/24 14:11:41 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int		pf_work_with_flags(char *str, char c, t_flags flags)
{
	char	*fill;
	int		width;
	int		prec;

	prec = pf_string_or_num_precision(&str, c, flags);
	if (c == 'p')
	{
		(str = ft_strappend_change_second("0x", &str));
		(prec += 2);
	}
	width = pf_determine_width(str, flags);
	flags.null || (flags.plus && !ft_strchr(str, '-')) ||\
		(flags.space && !ft_strchr(str, '-')) ? (width -= 1) : 0;
	if (width <= prec && (str = pf_tack_at_front(str, c, flags)))
		return (ft_putstr(str));
	flags.dot && c != 'f' ? flags.zero = 0 : 0;
	!flags.zero ? str = pf_tack_at_front(str, c, flags) : 0;
	fill = ft_strnew(width - prec);
	fill = what_to_fill(&str, fill, width - prec, flags);
	if (flags.dash)
		str = ft_strappend_change_second(str, &fill);
	else
		str = ft_strappend_change_first(&fill, str);
	flags.zero ? str = pf_tack_at_front(str, c, flags) : 0;
	return (ft_putstr(str));
}

int		pf_string_or_num_precision(char **str, char c, t_flags flags)
{
	int i;

	if ((c == 'f' || c == 'p' || c == 'e' || c == 'E')\
			&& flags.dot && !flags.precision && !flags.dot_star)
		return (ft_strlen(*str));
	if (c == 'g')
		return (ft_strlen(*str));
	if (c == 's' || c == 'c' || c == '%' ||\
		(flags.dot && !flags.precision && !flags.dot_star))
	{
		i = pf_determine_string_precision(str, flags);
		if (i == 0)
			*str = "";
		return (i);
	}
	else
		return (pf_determine_num_precision(str, flags));
}

char	*pf_tack_at_front(char *str, char c, t_flags flags)
{
	if (is_num_spec(c))
	{
		if (flags.plus && !ft_strchr(str, '-') && !ft_strchr(str, '+'))
			str = ft_strappend_change_second("+", &str);
		if (flags.space && !ft_strchr(str, '-') && !ft_strchr(str, '+'))
			str = ft_strappend_change_second(" ", &str);
	}
	return (str);
}
