/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:29:24 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/08/30 12:14:47 by bedos-sa         ###   ########.fr       */
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
		check_max_min(stacks);
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

void	check_moves(t_stacks *stacks)
{
	int	i;
	int	size;
	t_stack_a *head_a;

	head_a = stacks->head_a;
	size = ft_listsize_a(stacks->head_a);
	i = 0;
	while (i++ < size)
	{
		get_top_stack_a(stacks, head_a, i-1);
		if (head_a->content > stacks->values->max_b || \
			head_a->content < stacks->values->min_b)
			new_max_or_min_stack_b(stacks);
		else
			new_num_in_stack_b(stacks, head_a->content);
		check_double_moves(stacks);
		check_cost(stacks, i);
		head_a = head_a->next;
	}
}

void	check_cost(t_stacks *stacks, int i)
{
	stacks->moves->cost = stacks->moves->pb + stacks->moves->ra + stacks->moves->rb + stacks->moves->rr + stacks->moves->rra + stacks->moves->rrb + stacks->moves->rrr;
	if (i == 1 || (stacks->cheap->cost > stacks->moves->cost))
	{
		stacks->cheap->cost = stacks->moves->cost;
		stacks->cheap->pb = stacks->moves->pb;
		stacks->cheap->ra = stacks->moves->ra;
		stacks->cheap->rb = stacks->moves->rb;
		stacks->cheap->rr = stacks->moves->rr;
		stacks->cheap->rra = stacks->moves->rra;
		stacks->cheap->rrb = stacks->moves->rrb;
		stacks->cheap->rrr = stacks->moves->rrr;
	}
}

void	check_double_moves(t_stacks *stacks)
{
	stacks->moves->rr = 0;
	stacks->moves->rrr = 0;
	while (stacks->moves->ra != 0 && stacks->moves->rb != 0)
	{
		stacks->moves->ra--;
		stacks->moves->rb--;
		stacks->moves->rr++;
	}
	while (stacks->moves->rra != 0 && stacks->moves->rrb != 0)
	{
		stacks->moves->rra--;
		stacks->moves->rrb--;
		stacks->moves->rrr++;
	}
}

void	new_num_in_stack_b(t_stacks *stacks, int num)
{
	int	i;
	int	size;
	int	nbr;

	stacks->moves->rb = 0;
	stacks->moves->rrb = 0;
	nbr = search_num_stack_b(stacks, num);
	if (stacks->head_b->content == nbr)
		return ;
	i = find_index_stack_b(stacks, nbr);
	size = ft_listsize_b(stacks->head_b);
	if (size % 2 == 0)
	{
		if (i+1 > size/2)
			stacks->moves->rrb = (size - i);
		else
			stacks->moves->rb = i;
	}
	else
	{
		if (i > size/2)
			stacks->moves->rrb = (size - i);
		else
			stacks->moves->rb = i;
	}
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

void	get_top_stack_a(t_stacks *stacks, t_stack_a *head_a, int i)
{
	int			size;

	stacks->moves->pb = 1;
	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	if (stacks->head_a->content == head_a->content)
		return ;
	size = ft_listsize_a(stacks->head_a);
	if (size % 2 == 0)
	{
		if (i+1 > size/2)
			stacks->moves->rra = (size - i);
		else
			stacks->moves->ra = i;
	}
	else
	{
		if (i > size/2)
			stacks->moves->rra = (size - i);
		else
			stacks->moves->ra = i;
	}
}


void	new_max_or_min_stack_b(t_stacks *stacks)
{
	int			i;
	int			size;

	stacks->moves->rb = 0;
	stacks->moves->rrb = 0;
	if (stacks->head_b->content == stacks->values->max_b)
		return ;
	i = find_index_stack_b(stacks, stacks->values->max_b);
	size = ft_listsize_b(stacks->head_b);
	if (size % 2 == 0)
	{
		if (i+1 > size/2)
			stacks->moves->rrb = (size - i);
		else
			stacks->moves->rb = i;
	}
	else
	{
		if (i > size/2)
			stacks->moves->rrb = (size - i);
		else
			stacks->moves->rb = i;
	}
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
			break;
		head_b = head_b->next;
		i++;
	}
	return (i);
}
