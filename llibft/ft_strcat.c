/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdagai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:56:34 by tdagai            #+#    #+#             */
/*   Updated: 2020/02/20 17:04:13 by tdagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t ctr;
	size_t dlen;

	ctr = 0;
	dlen = ft_strlen(dest);
	while (src[ctr])
	{
		dest[dlen + ctr] = src[ctr];
		ctr++;
	}
	dest[dlen + ctr] = '\0';
	return (dest);
}
