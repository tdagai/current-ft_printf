/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_flags_with.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 10:28:22 by teva              #+#    #+#             */
/*   Updated: 2020/06/25 16:47:15 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		pf_work_with_flags(char *str, char c, t_flags flags)
{
	char	*fill;
	int		width;
	int		prec;

	prec = pf_string_or_num_precision(&str, c, flags);
	if (c == 'p')
	{
		str = ft_strappend_change_second("0x", &str);
		prec += 2;
	}
	width = pf_determine_width(str, flags);
	flags.null ? (width -= 1) : 0;
	if (width <= prec)
		return (ft_putstr(str));
	fill = ft_strnew(width - prec);
	fill = what_to_fill(&str, fill, width - prec, flags);
	if (flags.dash)
		str = ft_strappend_change_second(str, &fill);
	else
		str = ft_strappend_change_first(&fill, str);
	return (ft_putstr(str));
}

int		pf_string_or_num_precision(char **str, char c, t_flags flags)
{
	int i;

	if (c == 'p' && flags.dot && !flags.precision && !flags.dot_star)
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
