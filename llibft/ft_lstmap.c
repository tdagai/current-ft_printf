/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdagai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 17:23:48 by tdagai            #+#    #+#             */
/*   Updated: 2020/04/29 12:53:21 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new_lst;
	t_list	*head;

	if (!lst || !f)
		return (NULL);
	head = NULL;
	while (lst)
	{
		temp = lst;
		temp->content = f(lst->content);
		if (new_lst == NULL)
			new_lst = ft_lstnew(temp->content);
		else
			new_lst->next = ft_lstnew(temp->content);
		ft_lstdelone(&temp, del);
		if (!head)
			head = new_lst;
		if (!new_lst)
			return (head);
		else if (new_lst->next)
			new_lst = new_lst->next;
		lst = lst->next;
	}
	return (head);
}
