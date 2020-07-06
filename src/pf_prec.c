/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_prec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 13:21:07 by teva              #+#    #+#             */
/*   Updated: 2020/06/25 16:44:20 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			pf_determine_string_precision(char **str, t_flags flags)
{
	int len;

	if (flags.dot && !flags.precision && !flags.dot_star)
		return (0);
	len = ft_strlen(*str);
	if (flags.precision > 0 && flags.precision < len)
		*str = ft_downsize(*str, flags.precision);
	else if (flags.dot_star > 0 && flags.dot_star < len && !flags.dot_star_neg)
		*str = ft_downsize(*str, flags.dot_star);
	return (ft_strlen(*str));
}

char		*if_neg(char *str, char **fill, t_flags flags)
{
	int		i;
	char	*temp;

	temp = str + 1;
	str = ft_downsize(str, ft_strlen(str) - 1);
	i = 0;
	while (temp[i])
	{
		str[i] = temp[i];
		i++;
	}
	if (flags.zero > 0)
		*fill = ft_strappend_change_second("-", fill);
	else
		*fill = ft_strappend_change_second("-0", fill);
	return (str);
}

int			pf_determine_num_precision(char **str, t_flags flags)
{
	int		len;
	char	*fill;

	if (flags.dot && !flags.precision && !flags.dot_star)
		return (0);
	len = ft_strlen(*str);
	if (flags.precision > 0 && flags.precision > len)
	{
		fill = ft_strnew(flags.precision - len);
		fill = ft_strfill(fill, 48, flags.precision - len);
		if (*str[0] == '-')
			*str = if_neg(*str, &fill, flags);
		*str = ft_strappend_change_second(fill, str);
		ft_strdel(&fill);
	}
	else if (flags.dot_star && flags.dot_star > len && !flags.dot_star_neg)
	{
		fill = ft_strnew(flags.dot_star - len);
		fill = ft_strfill(fill, 48, flags.dot_star - len);
		if (*str[0] == '-')
			*str = if_neg(*str, &fill, flags);
		*str = ft_strappend_change_second(fill, str);
		ft_strdel(&fill);
	}
	return (ft_strlen(*str));
}
