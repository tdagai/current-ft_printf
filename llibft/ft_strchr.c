/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdagai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:43:34 by tdagai            #+#    #+#             */
/*   Updated: 2020/02/20 13:54:06 by tdagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		ctr;

	ctr = 0;
	while (str[ctr] && str[ctr] != c)
		ctr++;
	if (str[ctr] == c)
		return ((char *)(str + ctr));
	else
		return (NULL);
}
