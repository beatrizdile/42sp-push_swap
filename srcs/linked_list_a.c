/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:57:07 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/08/30 15:12:02 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_a	*create_list_a(int argc, char **argv)
{
	int			i;
	t_stack_a	*head_a;
	t_stack_a	*tmp;

	i = 1;
	head_a = ft_newnode_a(ft_atoi(argv[i]));
	tmp = head_a;
	while (++i < argc)
	{
		tmp->next = ft_newnode_a(ft_atoi(argv[i]));
		tmp = tmp->next;
		tmp->next = NULL;
	}
	return (head_a);
}

t_stack_a	*ft_newnode_a(int content)
{
	t_stack_a	*ptr;

	ptr = (t_stack_a *)malloc(sizeof(t_stack_a));
	if (!ptr)
		return (NULL);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}

void	ft_clearnodes_a(t_stack_a **lst)
{
	t_stack_a	*ptr;

	while (*lst != NULL)
	{
		ptr = *lst;
		*lst = ptr->next;
		free(ptr);
	}
}

int	ft_listsize_a(t_stack_a *head)
{
	int	count;

	count = 0;
	while (head != NULL)
	{
		count++;
		head = head->next;
	}
	return (count);
}

t_stack_a	*ft_lstlast_a(t_stack_a *head_a)
{	
	if (head_a == NULL)
		return (NULL);
	while (head_a->next != NULL)
		head_a = head_a->next;
	return (head_a);
}
