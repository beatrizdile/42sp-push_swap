/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_max.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:43:07 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/08/23 14:20:45 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_max(t_stacks *stacks)
{
	t_values	*values;
	t_stack_a	*head_a;
	// t_stack_b	*head_b;

	values = ft_calloc(1, sizeof(t_values));
	stacks->values = values;
	head_a = stacks->head_a;
	// head_b = stacks->head_b;
	check_max_a(stacks, head_a);
	// if (head_a != NULL)
	// 	check_max_b(head_b);
	ft_printf("-------MAX-A:-%d------\n", values->max_a);
}

void	check_max_a(t_stacks *stacks, t_stack_a *head_a)
{
	int	i;
	int	size;
	
	i = 0;
	size = ft_listsize_a(head_a);
	stacks->values->max_a = head_a->content;
	while (i < size)
	{
		if (stacks->values->max_a < head_a->content)
			stacks->values->max_a = head_a->content;
		head_a = head_a->next;
		i++;
	}
}

