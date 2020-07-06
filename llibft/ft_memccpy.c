/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdagai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 22:12:27 by tdagai            #+#    #+#             */
/*   Updated: 2020/02/19 22:35:27 by tdagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			ctr;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	ctr = 0;
	while (ctr < n)
	{
		d[ctr] = s[ctr];
		if (d[ctr] == (unsigned char)c)
			return ((void *)(dest + ctr + 1));
		ctr++;
	}
	return (NULL);
}
