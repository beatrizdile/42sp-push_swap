/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_min.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:43:41 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/08/23 16:52:51 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_min(t_stacks *stacks)
{
	check_min_a(stacks, stacks->head_a);
	if (stacks->head_b != NULL)
		check_min_b(stacks, stacks->head_b);
}

void	check_min_a(t_stacks *stacks, t_stack_a *head_a)
{
	int	i;
	int	size;
	
	i = 0;
	size = ft_listsize_a(head_a);
	stacks->values->min_a = head_a->content;
	while (i < size)
	{
		if (stacks->values->min_a > head_a->content)
			stacks->values->min_a = head_a->content;
		head_a = head_a->next;
		i++;
	}
}

void	check_min_b(t_stacks *stacks, t_stack_b *head_b)
{
	int	i;
	int	size;
	
	i = 0;
	size = ft_listsize_b(head_b);
	stacks->values->min_b = head_b->content;
	while (i < size)
	{
		if (stacks->values->min_b > head_b->content)
			stacks->values->min_b = head_b->content;
		head_b = head_b->next;
		i++;
	}
}
