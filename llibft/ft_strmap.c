/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdagai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 13:46:32 by tdagai            #+#    #+#             */
/*   Updated: 2020/02/21 16:14:29 by tdagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh;
	int		ctr;

	if (!s)
		return (NULL);
	if (!(fresh = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	ctr = 0;
	while (s[ctr])
	{
		fresh[ctr] = (*f)(s[ctr]);
		ctr++;
	}
	fresh[ctr] = '\0';
	return (fresh);
}
