/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdagai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:32:34 by tdagai            #+#    #+#             */
/*   Updated: 2020/02/20 16:08:29 by tdagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		ctr;
	char	*dup;

	if (!(dup = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	ctr = 0;
	while (str[ctr])
	{
		dup[ctr] = str[ctr];
		ctr++;
	}
	if (str[ctr] == '\0')
		dup[ctr] = '\0';
	return (dup);
}
