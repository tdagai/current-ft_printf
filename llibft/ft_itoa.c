/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdagai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 15:31:49 by tdagai            #+#    #+#             */
/*   Updated: 2020/02/22 19:05:42 by tdagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	parse_digits(unsigned int i)
{
	unsigned int size;

	size = 0;
	while (i >= 10)
	{
		i /= 10;
		size++;
	}
	return (size + 1);
}

char		*ft_itoa(int n)
{
	char				*convert;
	unsigned int		len;
	unsigned int		ctr;
	unsigned int		nb;

	if (n < 0)
		nb = (unsigned int)(n * -1);
	else
		nb = (unsigned int)n;
	len = (unsigned int)parse_digits(nb);
	ctr = 0;
	if (!(convert = (char *)malloc(sizeof(char) * (len + 1 + (n < 0 ? 1 : 0)))))
		return (0);
	if (n < 0 && (convert[ctr] = '-'))
		len++;
	ctr = len - 1;
	while (nb >= 10)
	{
		convert[ctr--] = (char)(nb % 10 + 48);
		nb /= 10;
	}
	convert[ctr] = (char)(nb % 10 + 48);
	convert[len] = '\0';
	return (convert);
}
