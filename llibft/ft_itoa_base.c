/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdagai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 15:31:49 by tdagai            #+#    #+#             */
/*   Updated: 2020/06/15 12:20:02 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_parse_digits(long long int i, int base)
{
	int size;

	size = 0;
	while (i >= (long long int)base)
	{
		i /= base;
		size++;
	}
	return (size + 1);
}

static char	big_base(long long int nb, int base)
{
	if (nb % base == 10)
		return ('a');
	else if (nb % base == 11)
		return ('b');
	else if (nb % base == 12)
		return ('c');
	else if (nb % base == 13)
		return ('d');
	else if (nb % base == 14)
		return ('e');
	else if (nb % base == 15)
		return ('f');
	else
		return ((char)(nb % base + 48));
}

char		*ft_itoa_base(long long int n, int base)
{
	char				*convert;
	long long int		len;
	long long int		ctr;
	long long int		nb;

	if (n < 0)
		nb = (long long int)(n * -1);
	else
		nb = (long long int)n;
	len = (long long int)ft_parse_digits(nb, base);
	ctr = 0;
	if (!(convert = (char *)malloc(sizeof(char) * (len + 1 + (n < 0 ? 1 : 0)))))
		return (0);
	if (n < 0 && (convert[ctr] = '-'))
		len++;
	ctr = len - 1;
	while (nb >= (long long int)base)
	{
		convert[ctr--] = big_base(nb, base);
		nb /= base;
	}
	convert[ctr] = big_base(nb, base);
	convert[len] = '\0';
	return (convert);
}
