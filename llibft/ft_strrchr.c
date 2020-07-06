/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdagai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:55:39 by tdagai            #+#    #+#             */
/*   Updated: 2020/02/20 14:01:01 by tdagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		ctr;
	int		found;
	int		location;

	ctr = 0;
	found = 0;
	location = 0;
	while (ctr <= (int)ft_strlen(str))
	{
		if (str[ctr] == c)
		{
			found = 1;
			location = ctr;
		}
		ctr++;
	}
	if (found)
		return ((char *)(str + location));
	else
		return (NULL);
}
