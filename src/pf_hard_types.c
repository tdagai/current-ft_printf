/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_hard_types.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 08:56:53 by teva              #+#    #+#             */
/*   Updated: 2020/06/25 16:43:25 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*pf_ptraddr(va_list ap)
{
	char	*str;
	void	*ptr;

	ptr = va_arg(ap, void *);
	str = ft_itoa_base_unsigned((unsigned long long int)ptr, 16);
	return (str);
}

char	*pf_hex(va_list ap, char c)
{
	unsigned long long int		i;
	char						*str;

	i = va_arg(ap, unsigned long long int);
	str = ft_itoa_base_unsigned((unsigned long long int)i, 16);
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
