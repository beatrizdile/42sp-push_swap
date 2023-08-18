/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:23:08 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/08/18 16:00:17 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stacks *stacks, char ch)
{
	t_stack_a	*head_a;
	t_stack_b	*head_b;

	head_a = stacks->head_a;
	head_b = stacks->head_b;
	if (ch == 'a')
	{
		if (head_a == NULL || head_a->next == NULL)
			return ;
		ft_swap_a(head_a);
	}
	else if (ch == 'b')
	{
		if (head_b == NULL || head_b->next == NULL)
			return ;
		ft_swap_b(head_b);
	}
	else
	{
		if (head_a == NULL || head_a->next == NULL || head_b == NULL || head_b->next == NULL)
			return ;
		ft_swap_a(head_a);
		ft_swap_b(head_b);
	}
}

void	ft_swap_a(t_stack_a *head_a)
{
	int	tmp;

	ft_printf("primeiro: %d\n", head_a->content);
	ft_printf("segundo: %d\n", head_a->next->content);
	tmp = head_a->content;
	head_a->content = head_a->next->content;
	head_a->next->content = tmp;
	ft_printf("novo primeiro: %d\n", head_a->content);
	ft_printf("novo segundo: %d\n", head_a->next->content);
}

void	ft_swap_b(t_stack_b *head_b)
{
	int	tmp;

	ft_printf("primeiro b: %d\n", head_b->content);
	ft_printf("segundo b: %d\n", head_b->next->content);
	tmp = head_b->content;
	head_b->content = head_b->next->content;
	head_b->next->content = tmp;
	ft_printf("novo primeiro b: %d\n", head_b->content);
	ft_printf("novo segundo b: %d\n", head_b->next->content);
}
