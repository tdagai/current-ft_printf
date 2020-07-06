/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdagai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:12:45 by tdagai            #+#    #+#             */
/*   Updated: 2020/04/15 16:55:38 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t destlen;
	size_t ctr;
	size_t index;

	destlen = ft_strlen(dest);
	ctr = ft_strlen(src);
	if (size == 0)
		return (ctr);
	if (size <= destlen)
		ctr += size;
	else
		ctr += destlen;
	index = 0;
	while (src[index] != '\0' && destlen < size - 1)
		dest[destlen++] = src[index++];
	dest[destlen] = '\0';
	return (ctr);
}
