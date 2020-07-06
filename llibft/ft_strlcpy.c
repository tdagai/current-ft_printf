/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 11:13:12 by teva              #+#    #+#             */
/*   Updated: 2020/04/15 16:51:38 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	ctr;
	size_t	to_cpy;

	if (size != 0)
	{
		to_cpy = size - 1;
		ctr = 0;
		while (ctr < to_cpy && src[ctr])
		{
			dest[ctr] = src[ctr];
			++ctr;
		}
		dest[ctr] = '\0';
	}
	return (ft_strlen(src));
}
