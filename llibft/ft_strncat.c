/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdagai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 20:56:36 by tdagai            #+#    #+#             */
/*   Updated: 2020/02/20 20:59:07 by tdagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t ctr;
	size_t dlen;

	ctr = 0;
	dlen = ft_strlen(dest);
	while (src[ctr] && ctr < n)
	{
		dest[dlen + ctr] = src[ctr];
		ctr++;
	}
	dest[dlen + ctr] = '\0';
	return (dest);
}
