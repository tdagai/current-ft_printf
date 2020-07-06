/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_downsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 13:30:51 by teva              #+#    #+#             */
/*   Updated: 2020/06/05 13:58:44 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_downsize(char *str, int size)
{
	char	*newstr;
	int		ctr;

	ctr = 0;
	newstr = ft_strnew(size);
	while (ctr < size)
	{
		newstr[ctr] = str[ctr];
		ctr++;
	}
	newstr[ctr] = '\0';
	return (newstr);
}
