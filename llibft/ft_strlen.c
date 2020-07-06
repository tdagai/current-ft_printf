/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdagai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 20:04:35 by tdagai            #+#    #+#             */
/*   Updated: 2020/06/19 13:04:29 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlen(const char *str)
{
	int ctr;

	ctr = 0;
	while (str[ctr] != '\0')
		ctr++;
	return (ctr);
}

size_t	ft_strlen_for_e(const char *str)
{
	int ctr;

	ctr = 0;
	while (str[ctr] != 'e' && str[ctr] != 'E')
		ctr++;
	return (ctr);
}
