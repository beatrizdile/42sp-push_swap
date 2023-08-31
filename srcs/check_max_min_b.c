/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_max_min_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:20:22 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/08/31 16:11:58 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_max_min_b(t_stacks *stacks)
{
	if (stacks->head_b != NULL)
	{
		check_max_b(stacks, stacks->head_b);
		check_min_b(stacks, stacks->head_b);
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
