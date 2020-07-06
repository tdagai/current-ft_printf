/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_hard_types_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 08:56:53 by teva              #+#    #+#             */
/*   Updated: 2020/06/22 14:55:08 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*pf_ptraddr(va_list ap)
{
	char	*str;
	void	*ptr;

	ptr = va_arg(ap, void *);
	str = ft_itoa_base_unsigned((unsigned long long int)ptr, 16);
	return (str);
}

char	*pf_hex(va_list ap, char c, t_flags flags)
{
	unsigned long long int		i;
	char						*str;

	if (flags.h)
		i = (unsigned short int)va_arg(ap, unsigned int);
	else if (flags.hh)
		i = (unsigned char)va_arg(ap, unsigned int);
	else if (flags.l)
		i = va_arg(ap, unsigned long int);
	else if (flags.ll)
		i = va_arg(ap, unsigned long long int);
	else
		i = va_arg(ap, unsigned int);
	str = ft_itoa_base_unsigned((unsigned long long int)i, 16);
	flags.pound ? (str = ft_strappend_change_second("0x", &str)) : 0;
	if (c == 'X')
	{
		i = 0;
		while (str[i])
		{
			str[i] = ft_toupper(str[i]);
			i++;
		}
	}
	return (str);
}
