/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_treat_flags_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 12:31:53 by teva              #+#    #+#             */
/*   Updated: 2020/06/12 12:41:35 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int		treat_width(char *parsed)
{
	char	*traverse;
	char	*width;
	int		ret;

	traverse = parsed + 1;
	if ((*traverse >= '0' && *traverse <= '9'))
	{
		while (*traverse >= '0' && *traverse <= '9')
			traverse++;
		width = ft_substr(parsed, 0, ft_strlen(parsed) - ft_strlen(traverse));
		ret = ft_atoi(width);
	}
	else
	{
		width = ft_substr(parsed, 0, 1);
		ret = ft_atoi(width);
	}
	return (ret < 0 ? ret = -ret : ret);
}

int		treat_star(va_list ap, t_flags *flags)
{
	int	i;

	i = va_arg(ap, int);
	if (i < 0)
	{
		flags->dash = 1;
		flags->dot_star_neg = 1;
		flags->zero = 0;
	}
	return (i > 0 ? i : -i);
}
