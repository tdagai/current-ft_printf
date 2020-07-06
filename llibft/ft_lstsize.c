/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 12:15:48 by teva              #+#    #+#             */
/*   Updated: 2020/04/20 12:27:13 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		ctr;
	t_list	*temp;

	if (!lst)
		return (0);
	temp = lst;
	ctr = 1;
	while (temp->next)
	{
		ctr++;
		temp = temp->next;
	}
	return (ctr);
}
