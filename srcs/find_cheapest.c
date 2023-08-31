/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:29:24 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/08/31 16:19:56 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_cheapest(t_stacks *stacks)
{
	struct t_moves	*moves;
	struct t_cheap	*cheap;
	t_values		*values;

	moves = ft_calloc(1, sizeof(t_moves));
	stacks->moves = moves;
	cheap = ft_calloc(1, sizeof(t_cheap));
	stacks->cheap = cheap;
	values = ft_calloc(1, sizeof(t_values));
	stacks->values = values;
	while (ft_listsize_a(stacks->head_a) != 3)
	{
		check_max_min_b(stacks);
		check_moves(stacks);
		do_cheap_moves(stacks);
	}
}

void	do_cheap_moves(t_stacks *stacks)
{
	while (stacks->cheap->ra-- != 0)
		ft_rotate(stacks, 'a');
	while (stacks->cheap->rb-- != 0)
		ft_rotate(stacks, 'b');
	while (stacks->cheap->rr-- != 0)
		ft_rotate(stacks, 'r');
	while (stacks->cheap->rra-- != 0)
		ft_rev_rotate(stacks, 'a');
	while (stacks->cheap->rrb-- != 0)
		ft_rev_rotate(stacks, 'b');
	while (stacks->cheap->rrr-- != 0)
		ft_rev_rotate(stacks, 'r');
	while (stacks->cheap->pb-- != 0)
		ft_push(stacks, 'b');
}

int	search_num_stack_b(t_stacks *stacks, int nbr)
{
	t_stack_b	*head_b;
	int			size;
	int			flag;
	int			i;

	i = 0;
	flag = 0;
	head_b = stacks->head_b;
	size = ft_listsize_b(stacks->head_b);
	while (flag == 0)
	{
		i = 0;
		nbr--;
		head_b = stacks->head_b;
		while (i++ < size)
		{
			if (head_b->content == nbr)
				flag = 1;
			head_b = head_b->next;
		}
	}
	return (nbr);
}

int	find_index_stack_b(t_stacks *stacks, int nbr)
{
	t_stack_b	*head_b;
	int			size;
	int			i;

	i = 0;
	head_b = stacks->head_b;
	size = ft_listsize_b(stacks->head_b);
	while (i < size)
	{
		if (head_b->content == nbr)
			break ;
		head_b = head_b->next;
		i++;
	}
	return (i);
}
