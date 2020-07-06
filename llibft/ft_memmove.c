/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdagai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 22:39:10 by tdagai            #+#    #+#             */
/*   Updated: 2020/02/20 12:18:59 by tdagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	ctr;
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (d == ((char *)src))
		return (NULL);
	ctr = 0;
	if (s < d)
	{
		while (++ctr <= n)
			d[n - ctr] = s[n - ctr];
	}
	else
	{
		while (n-- > 0)
			*(d++) = *(s++);
	}
	return (dest);
}
