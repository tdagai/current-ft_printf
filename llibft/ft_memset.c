/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdagai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:12:09 by tdagai            #+#    #+#             */
/*   Updated: 2020/02/19 19:27:40 by tdagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *offset, int x, size_t n)
{
	unsigned char *ptr;

	ptr = offset;
	while (n > 0)
	{
		*ptr = x;
		ptr++;
		n--;
	}
	return (offset);
}
