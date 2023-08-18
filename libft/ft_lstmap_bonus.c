/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:46:39 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/08/17 17:31:54 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*head_a;
	t_list	*map;

	if (!lst)
		return (NULL);
	map = NULL;
	temp = lst;
	while (temp != NULL)
	{
		head_a = ft_lstnew(f(temp->content));
		if (head_a)
			ft_lstadd_back(&map, head_a);
		else
			ft_lstclear(&head_a, del);
		temp = temp->next;
	}
	return (map);
}
