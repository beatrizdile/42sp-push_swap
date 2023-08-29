/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:29:24 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/08/28 14:27:14 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_cheapest(t_stacks *stacks)
{
	t_values	*values;

	values = ft_calloc(1, sizeof(t_values));
	stacks->values = values;
	check_max(stacks);
	check_min(stacks);
	check_moves(stacks);
}

void	check_moves(t_stacks *stacks)
{
	int	i;
	int	size;
	t_stack_a *head_a;
	struct t_moves	*moves;

	moves = ft_calloc(1, sizeof(t_moves));
	stacks->moves = moves;
	head_a = stacks->head_a;
	size = ft_listsize_a(stacks->head_a);
	i = 0;
	while (i++ < size)
	{
		get_top_stack_a(stacks, head_a, i-1);
		if (head_a->content > stacks->values->max_b || \
			head_a->content < stacks->values->min_b)
			new_max_or_min_stack_b(stacks);
		ft_printf("pb: %d | ra: %d | rra: %d\n", stacks->moves->pb, stacks->moves->ra, stacks->moves->rra);
		ft_printf("rb: %d | rrb: %d\n", stacks->moves->rb, stacks->moves->rrb);
		ft_printf("----------------------------\n");
		head_a = head_a->next;
	}
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
	move_max_stack_b(stacks);
}

void	move_max_stack_b(t_stacks *stacks)
{
	int			i;
	int			size;

	if (stacks->head_b->content == stacks->values->max_b)
		return ;
	i = find_max_index_stack_b(stacks);
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

int	find_max_index_stack_b(t_stacks *stacks)
{
	t_stack_b	*head_b;
	int			size;
	int			i;

	i = 0;
	head_b = stacks->head_b;
	size = ft_listsize_b(stacks->head_b);
	while (i < size)
	{
		if (head_b->content == stacks->values->max_b)
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
