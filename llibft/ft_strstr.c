/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdagai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 22:01:37 by tdagai            #+#    #+#             */
/*   Updated: 2020/02/20 23:06:04 by tdagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	ctr;
	size_t	i;

	if (!*needle)
		return ((char *)(haystack));
	ctr = 0;
	while (haystack[ctr])
	{
		if (haystack[ctr] == needle[0])
		{
			i = 1;
			while (needle[i] && haystack[ctr + i] == needle[i])
				++i;
			if (needle[i] == '\0')
				return ((char *)(&haystack[ctr]));
		}
		ctr++;
	}
	return (NULL);
}
