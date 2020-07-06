/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdagai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 23:16:37 by tdagai            #+#    #+#             */
/*   Updated: 2020/02/20 23:20:21 by tdagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	ctr;
	size_t	i;

	if (!*needle)
		return ((char *)(haystack));
	ctr = 0;
	while (haystack[ctr] && ctr < n)
	{
		if (haystack[ctr] == needle[0])
		{
			i = 1;
			while (needle[i] && haystack[ctr + i] == needle[i] && (ctr + i) < n)
				++i;
			if (needle[i] == '\0')
				return ((char *)(&haystack[ctr]));
		}
		ctr++;
	}
	return (NULL);
}
