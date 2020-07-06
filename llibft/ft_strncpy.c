/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdagai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:59:35 by tdagai            #+#    #+#             */
/*   Updated: 2020/02/23 19:28:18 by tdagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	ctr;
	size_t	len;

	ctr = 0;
	len = ft_strlen(src);
	while (ctr < len && ctr < n)
	{
		dest[ctr] = src[ctr];
		ctr++;
	}
	while (ctr < n && dest[ctr])
		dest[ctr++] = '\0';
	return (dest);
}
