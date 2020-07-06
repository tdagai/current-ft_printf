/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdagai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 21:51:56 by tdagai            #+#    #+#             */
/*   Updated: 2020/02/19 22:09:22 by tdagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				ctr;
	unsigned char		*d;
	const unsigned char	*s;

	if (dest == src)
		return (NULL);
	d = dest;
	s = src;
	ctr = 0;
	while (ctr < n)
	{
		d[ctr] = s[ctr];
		ctr++;
	}
	return (d);
}
