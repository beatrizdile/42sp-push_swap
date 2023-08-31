/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:34:22 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/08/31 16:13:36 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stacks *stacks, char ch)
{
	t_stack_a	*head_a;
	t_stack_b	*head_b;

	head_a = stacks->head_a;
	head_b = stacks->head_b;
	if (ch == 'a')
		ft_rotate_a(stacks, stacks->head_a, 1);
	else if (ch == 'b')
	{
		if (head_b == NULL || head_b->next == NULL)
			return ;
		ft_rotate_b(stacks, head_b, 1);
	}
	else
	{
		if (head_a == NULL || head_a->next == NULL || head_b == NULL
			|| head_b->next == NULL)
			return ;
		ft_rotate_a(stacks, stacks->head_a, 0);
		ft_rotate_b(stacks, head_b, 0);
		ft_printf("rr\n");
	}
}

void	ft_rotate_a(t_stacks *stacks, t_stack_a *head_a, int print)
{
	t_stack_a	*tmp_head;

	tmp_head = head_a;
	stacks->head_a = head_a->next;
	while (head_a->next != NULL)
		head_a = head_a->next;
	head_a->next = tmp_head;
	tmp_head->next = NULL;
	if (print != 0)
		ft_printf("ra\n");
}

void	ft_rotate_b(t_stacks *stacks, t_stack_b *head_b, int print)
{
	t_stack_b	*tmp_head;

	tmp_head = head_b;
	stacks->head_b = head_b->next;
	while (head_b->next != NULL)
		head_b = head_b->next;
	head_b->next = tmp_head;
	tmp_head->next = NULL;
	if (print != 0)
		ft_printf("rb\n");
}

t_stack_a	*ft_listlast_a(t_stack_a *head_a)
{
	if (head_a == NULL)
		return (NULL);
	while (head_a->next != NULL)
		head_a = head_a->next;
	return (head_a);
}

t_stack_b	*ft_listlast_b(t_stack_b *head_b)
{
	if (head_b == NULL)
		return (NULL);
	while (head_b->next != NULL)
		head_b = head_b->next;
	return (head_b);
}
