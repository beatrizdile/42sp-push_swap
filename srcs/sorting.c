/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:59:54 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/08/28 14:25:53 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_stacks *stacks)
{

	if (check_list_order(stacks))
		return ;
	if (ft_listsize_a(stacks->head_a) == 3)
		sort_three(stacks);
	print_linked_lists(stacks);
	ft_push(stacks, 'b');
	ft_push(stacks, 'b');
	move_cheapest(stacks);
	ft_printf("MAX A: %d\n", stacks->values->max_a);
	ft_printf("MIN A: %d\n", stacks->values->min_a);
	ft_printf("MAX B: %d\n", stacks->values->max_b);
	ft_printf("MIN B: %d\n", stacks->values->min_b);
	print_linked_lists(stacks);
}


void	print_linked_lists(t_stacks *stacks)
{
	int			count;
	t_stack_a	*head_a;

	head_a = stacks->head_a;
	t_stack_b	*head_b = stacks->head_b;
	count = 0;
	while (head_a != NULL)
	{
		ft_printf("content[%d] of stack A: %d\n", count, head_a->content);
		head_a = head_a->next;
		count++;
	}
	ft_printf("\n");
	count = 0;
	while (head_b != NULL)
	{
		ft_printf("content[%d] of stack B: %d\n", count, head_b->content);
		head_b = head_b->next;
		count++;
	}
	ft_printf("\n");
}
