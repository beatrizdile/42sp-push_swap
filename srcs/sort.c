/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:09:49 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/08/18 20:16:51 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_stacks *stacks)
{
	if (ft_listsize(stacks->head_a) == 3)
		sort_three(stacks);
	
}

void	sort_three(t_stacks *stacks)
{
	print_linked_lists(stacks);
	ft_swap(stacks, 'a');
	print_linked_lists(stacks);
}

void	print_linked_lists(t_stacks *stacks)
{	
	int			count;
	t_stack_a	*head_a = stacks->head_a;
	//t_stack_b	*head_b = stacks->head_b;

	count = 0;
	while (head_a != NULL)
	{
		ft_printf("content[%d] of stack a: %d\n", count, head_a->content);
		head_a = head_a->next;
		count++;
	}
	// count = 0;
	// while (head_b != NULL)
	// {
	// 	ft_printf("content[%d] of stack b: %d\n", count, head_b->content);
	// 	head_b = head_b->next;
	// 	count++;
	// }
}
