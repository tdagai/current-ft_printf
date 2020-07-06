/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdagai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 14:17:04 by tdagai            #+#    #+#             */
/*   Updated: 2020/04/18 17:13:16 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *))
{
	t_list	*temp;

	if (!alst || !(*alst))
		return ;
	temp = *alst;
	(del)(temp->content);
	if (temp->content == NULL)
	{
		free(temp);
		*alst = NULL;
	}
}
