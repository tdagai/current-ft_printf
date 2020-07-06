/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdagai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 12:56:05 by tdagai            #+#    #+#             */
/*   Updated: 2020/02/24 19:53:55 by tdagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	ctr;
	char			*str;

	if (s && f)
	{
		ctr = 0;
		str = s;
		while (str[ctr])
		{
			(*f)(ctr, &str[ctr]);
			ctr++;
		}
	}
}
