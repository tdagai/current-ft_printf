/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_flags_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 12:28:09 by teva              #+#    #+#             */
/*   Updated: 2020/06/25 15:55:00 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdio.h>

t_flags	flags_init(void)
{
	t_flags flags;

	flags.dash = 0;
	flags.width = 0;
	flags.dot = 0;
	flags.dot_star = 0;
	flags.dot_star_neg = 0;
	flags.precision = 0;
	flags.star = 0;
	flags.zero = 0;
	flags.null = 0;
	flags.h = 0;
	flags.hh = 0;
	flags.l = 0;
	flags.ll = 0;
	flags.capital_l = 0;
	flags.pound = 0;
	flags.space = 0;
	flags.plus = 0;
	return (flags);
}

char	*parse_flags(char *traverse, va_list ap, t_flags *flags)
{
	char	*head;
	char	*parsed;

	head = traverse;
	while (is_flag(*traverse))
		traverse++;
	parsed = ft_substr(head, 0, ft_strlen(head) - ft_strlen(traverse));
	*flags = present_flags(parsed, ap, *flags);
	return (traverse);
}

t_flags	present_flags(char *parsed, va_list ap, t_flags flags)
{
	while (*parsed)
	{
		if (*parsed == '-' || *parsed == '*' || *parsed == '0')
			flags = if_dash_or_star(parsed, ap, &flags);
		else if (*parsed == '#' || *parsed == '+' || *parsed == 'L' ||\
			*parsed == ' ')
			flags = if_bonus_flags(parsed, &flags);
		else if ((*parsed >= '0' && *parsed <= '9') && flags.width == 0 &&\
				flags.dot == 0)
			flags.width = treat_width(parsed);
		else if (*parsed == '.')
			flags = if_dot(++parsed, ap, &flags);
		else if (*parsed == 'h')
		{
			*(parsed + 1) == 'h' && (parsed++) ? (flags.hh = 1) : 0;
			flags.hh ? 0 : (flags.h = 1);
		}
		else if (*parsed == 'l')
		{
			*(parsed + 1) == 'l' && (parsed++) ? (flags.ll = 1) : 0;
			flags.ll ? 0 : (flags.l = 1);
		}
		parsed++;
	}
	return (flags);
}

char	*what_to_fill(char **str, char *fill, int diff, t_flags flags)
{
	if (flags.zero > 0)
	{
		fill = ft_strfill(fill, 48, diff);
		if (*str[0] == '-')
			*str = if_neg(*str, &fill, flags);
		return (fill);
	}
	else
		return (ft_strfill(fill, 32, diff));
}
