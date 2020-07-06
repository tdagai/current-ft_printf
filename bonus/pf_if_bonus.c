/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_if_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 14:16:05 by teva              #+#    #+#             */
/*   Updated: 2020/06/25 15:56:37 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_flags	if_dot(char *parsed, va_list ap, t_flags *flags)
{
	flags->dot = 1;
	if (*parsed == '*')
		flags->dot_star = treat_star(ap, flags);
	else if (*parsed >= '0' && *parsed <= '9')
		flags->precision = treat_width(parsed);
	else
		flags->precision = 0;
	return (*flags);
}

t_flags	if_bonus_flags(char *parsed, t_flags *flags)
{
	if (*parsed == '#')
		flags->pound = 1;
	else if (*parsed == '+')
	{
		flags->space = 0;
		flags->plus = 1;
	}
	else if (*parsed == 'L')
		flags->capital_l = 1;
	else if (*parsed == ' ' && !flags->space && !flags->plus)
		flags->space = 1;
	return (*flags);
}

t_flags	if_dash_or_star(char *parsed, va_list ap, t_flags *flags)
{
	if (*parsed == '-')
	{
		flags->zero = 0;
		flags->dash = 1;
	}
	else if (*parsed == '*')
		flags->star = treat_star(ap, flags);
	else if (*parsed == '0' && flags->width == 0 && flags->dash == 0)
		flags->zero = 1;
	return (*flags);
}
