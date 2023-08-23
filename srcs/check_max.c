/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_max.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:43:07 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/08/23 14:51:37 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_max(t_stacks *stacks)
{
	t_values	*values;

	values = ft_calloc(1, sizeof(t_values));
	stacks->values = values;
	check_max_a(stacks, stacks->head_a);
	if (stacks->head_b != NULL)
		check_max_b(stacks, stacks->head_b);
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

void	check_max_b(t_stacks *stacks, t_stack_b *head_b)
{
	int	i;
	int	size;
	
	i = 0;
	size = ft_listsize_b(head_b);
	stacks->values->max_b = head_b->content;
	while (i < size)
	{
		if (stacks->values->max_b < head_b->content)
			stacks->values->max_b = head_b->content;
		head_b = head_b->next;
		i++;
	}
}
