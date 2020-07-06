/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 12:34:16 by teva              #+#    #+#             */
/*   Updated: 2020/07/03 16:25:19 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char **ptraddr, size_t size)
{
	char	*newstr;
	size_t	len;

	len = ft_strlen(*ptraddr);
	if (size == 0 || !(newstr = ft_strnew(len + size)))
		return (NULL);
	ft_memmove(newstr, *ptraddr, len);
	free(*ptraddr);
	*ptraddr = newstr;
	return (newstr);
}
