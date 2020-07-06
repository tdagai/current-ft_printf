/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 12:28:09 by teva              #+#    #+#             */
/*   Updated: 2020/06/11 10:57:52 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
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
	int		ctr;

	ctr = 0;
	while (*parsed)
	{
		if (*parsed == '-')
			flags.dash = 1;
		else if (*parsed == '0' && flags.width == 0 && flags.dash == 0)
			flags.zero = 1;
		else if ((*parsed >= '0' && *parsed <= '9') && flags.width == 0 &&\
				flags.dot == 0)
			flags.width = treat_width(parsed);
		else if (*parsed == '*')
			flags.star = treat_star(ap, &flags);
		else if (*parsed == '.')
		{
			flags.dot = 1;
			parsed++;
			if (*parsed == '*')
				flags.dot_star = treat_star(ap, &flags);
			else if (*parsed >= '0' && *parsed <= '9')
				flags.precision = treat_width(parsed);
			else
				flags.precision = 0;
			flags.zero = 0;
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
