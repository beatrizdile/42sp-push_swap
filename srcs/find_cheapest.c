/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:29:24 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/08/29 15:19:55 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_cheapest(t_stacks *stacks)
{
	t_values	*values;

	values = ft_calloc(1, sizeof(t_values));
	stacks->values = values;
	check_max_min(stacks);
	check_moves(stacks);
}

void	check_moves(t_stacks *stacks)
{
	int	i;
	int	size;
	t_stack_a *head_a;
	struct t_moves	*moves;
	struct t_cheap	*cheap;

	moves = ft_calloc(1, sizeof(t_moves));
	stacks->moves = moves;
	cheap = ft_calloc(1, sizeof(t_cheap));
	stacks->cheap = cheap;
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
		ft_printf("pb: %d | ra: %d | rra: %d\n", stacks->moves->pb, stacks->moves->ra, stacks->moves->rra);
		ft_printf("rb: %d | rrb: %d\n", stacks->moves->rb, stacks->moves->rrb);
		ft_printf("rr: %d | rrr: %d\n", stacks->moves->rr, stacks->moves->rrr);
		ft_printf("----------------------------\n");
		head_a = head_a->next;
	}
	ft_printf("----------------------------\n");
	ft_printf("CHEAPEST: %d\n", stacks->cheap->cost);
	ft_printf("pb: %d | ra: %d | rra: %d\n", stacks->cheap->pb, stacks->cheap->ra, stacks->cheap->rra);
	ft_printf("rb: %d | rrb: %d\n", stacks->cheap->rb, stacks->cheap->rrb);
	ft_printf("rr: %d | rrr: %d\n", stacks->cheap->rr, stacks->cheap->rrr);
	ft_printf("----------------------------\n");
}

void	check_cost(t_stacks *stacks, int i)
{
	stacks->moves->cost = stacks->moves->pb + stacks->moves->ra + stacks->moves->rb + stacks->moves->rr + stacks->moves->rra + stacks->moves->rrb + stacks->moves->rrr;
	ft_printf("COST: %d\n", stacks->moves->cost);
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
	ft_printf("CHEAPEST: %d\n", stacks->cheap->cost);
	
}

void	check_double_moves(t_stacks *stacks)
{
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

// primeiro check se o valor a ser passado de A para B é maior que o MAX de B ou
// menor que o MIN de B
// Se sim, precisamos colocar ele acima do MAX de B
//		o primeiro elemento é o MAX de B?
//		se não,
//		devemos calcular quantos movimentos são precisos para deixar o MAX de B
//		no topo da stack 
//		+ quanto custa mover elemento para o topo da stack A + push
// Se não, colocar em algum lugar na stack
//		calcular quanto custa para colocar em algum lugar na stack B + para deixar
//		no topo da stack A
// Calcular quantos movimentos de rotação podem ser feitos em conjunto
