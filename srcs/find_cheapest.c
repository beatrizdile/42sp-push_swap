/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:29:24 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/08/26 14:40:09 by bedos-sa         ###   ########.fr       */
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

	i = 0;
	head_a = stacks->head_a;
	size = ft_listsize_a(stacks->head_a);
	while (i++ < size)
	{
		if (head_a->content > stacks->values->max_b || \
			head_a->content < stacks->values->min_b)
			new_max_min(stacks);
		head_a = head_a->next;
	}
}

void	new_max_min(t_stacks *stacks)
{
	struct t_moves	*moves;
	moves = ft_calloc(1, sizeof(t_moves));
	stacks->moves = moves;
	get_max_top(stacks);
	ft_printf("rb: %d\n", stacks->moves->rb);
	ft_printf("rrb: %d\n", stacks->moves->rrb);
}

void	get_max_top(t_stacks *stacks)
{
	int			i;
	int			size;
	t_stack_b	*head_b;

	if (stacks->head_b->content == stacks->values->max_b)
		return ;
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

// primeiro check se o valor a ser passado de A para B é maior que o MAX de B ou
// menor que o MIN de B
// Se sim, precisamos colocar ele acima do MAX de B
//		o primeiro elemento é o MAX de B?
//		se não,
//		devemos calcular quantos movimentos são precisos para deixar o MAX de B
//		no topo da stack 
//		+ quanto custa mover elemento para o topo da stack A + push
// Se não, colocar em algum lugar na stack
//		calcular quanto custa para colocar em algum lugar
