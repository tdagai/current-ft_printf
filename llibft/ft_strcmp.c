/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdagai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:52:55 by tdagai            #+#    #+#             */
/*   Updated: 2020/02/20 15:26:32 by tdagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	size_t	ctr;
	size_t	len1;
	size_t	len2;

	ctr = 0;
	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	while (*str1 == *str2 && (ctr < len1 || ctr < len2))
	{
		str1++;
		str2++;
		ctr++;
	}
	return ((unsigned char)(*str1) - (unsigned char)(*str2));
}
