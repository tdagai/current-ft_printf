/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdagai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:16:49 by tdagai            #+#    #+#             */
/*   Updated: 2020/02/21 16:20:14 by tdagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*fresh;
	unsigned int		ctr;

	if (!s)
		return (NULL);
	if (!(fresh = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	ctr = 0;
	while (s[ctr])
	{
		fresh[ctr] = (*f)(ctr, s[ctr]);
		ctr++;
	}
	fresh[ctr] = '\0';
	return (fresh);
}
