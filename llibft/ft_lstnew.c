/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdagai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 13:57:53 by tdagai            #+#    #+#             */
/*   Updated: 2020/04/18 12:23:09 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content)
{
	t_list	*node;

	if (!(node = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
		node->content = NULL;
	else
	{
		if (!(node->content = (void *)malloc(sizeof(void *))))
			return (NULL);
		ft_memcpy(node->content, content, ft_strlen((char *)content));
	}
	node->next = NULL;
	return (node);
}
