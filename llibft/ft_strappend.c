/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 10:04:28 by teva              #+#    #+#             */
/*   Updated: 2020/06/02 16:08:34 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strappend_change_first(char **dest, const char *src)
{
	ft_realloc(dest, ft_strlen(src));
	ft_strcpy(*dest + ft_strlen(*dest), src);
	return (*dest);
}

char	*ft_strappend_change_second(const char *str, char **dest)
{
	char	*newstr;

	if (!str || !*dest)
		return (NULL);
	if (!(newstr = ft_strnew(ft_strlen(*dest) + ft_strlen(str))))
		return (NULL);
	ft_strcpy(newstr, str);
	ft_strcat(newstr, *dest);
	ft_strdel(dest);
	*dest = newstr;
	return (newstr);
}
