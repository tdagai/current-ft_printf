/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:27:58 by teva              #+#    #+#             */
/*   Updated: 2020/06/24 14:07:05 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfill(char *str, char fill, size_t len)
{
	size_t	ctr;

	ctr = 0;
	while (ctr < len)
	{
		str[ctr] = fill;
		ctr++;
	}
	str[ctr] = '\0';
	return (str);
}
