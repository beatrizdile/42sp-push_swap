/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rev_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:03:26 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/08/23 11:24:27 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate(t_stacks *stacks, char ch)
{
	t_stack_a	*head_a;
	t_stack_b	*head_b;

	head_a = stacks->head_a;
	head_b = stacks->head_b;
	if (ch == 'a')
		ft_rev_rotate_a(stacks, stacks->head_a, 1);
	else if (ch == 'b')
	{
		if (head_b == NULL || head_b->next == NULL)
			return ;
		ft_rev_rotate_b(stacks, head_b, 1);
	}
	else
	{
		if (head_a == NULL || head_a->next == NULL || head_b == NULL
			|| head_b->next == NULL)
			return ;
		ft_rev_rotate_a(stacks, stacks->head_a, 0);
		ft_rev_rotate_b(stacks, head_b, 0);
		ft_printf("rrr\n");
	}
}

void	ft_rev_rotate_a(t_stacks *stacks, t_stack_a *head_a, int print)
{
	t_stack_a	*tmp_node;
	int			i;
	int			size;

	size = ft_listsize_a(head_a);
	tmp_node = head_a;
	while (head_a->next != NULL)
		head_a = head_a->next;
	head_a->next = tmp_node;
	stacks->head_a = head_a;
	tmp_node = stacks->head_a;
	i = 0;
	while (i++ < size - 1)
		tmp_node = tmp_node->next;
	tmp_node->next = NULL;
	if (print != 0)
		ft_printf("rra\n");
}

void	ft_rev_rotate_b(t_stacks *stacks, t_stack_b *head_b, int print)
{
	t_stack_b	*tmp_node;
	int			i;
	int			size;

	size = ft_listsize_b(head_b);
	tmp_node = head_b;
	while (head_b->next != NULL)
		head_b = head_b->next;
	head_b->next = tmp_node;
	stacks->head_b = head_b;
	tmp_node = stacks->head_b;
	i = 0;
	while (i++ < size - 1)
		tmp_node = tmp_node->next;
	tmp_node->next = NULL;
	if (print != 0)
		ft_printf("rrb\n");
}
