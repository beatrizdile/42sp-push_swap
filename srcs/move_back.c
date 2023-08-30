/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:53:24 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/08/30 14:42:31 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_stack_a(t_stacks *stacks)
{
	t_stack_b	*head_b;
	
	head_b = stacks->head_b;
	check_max_min_a(stacks);
	if (head_b->content < stacks->values->min_a)
		new_min_stack_a(stacks);
	// else if (head_b->content > stacks->values->max_a)
	// 	new_max_stack_a(stacks);
}

void	new_min_stack_a(t_stacks *stacks)
{
	int			i;
	int			size;

	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	if (stacks->head_a->content == stacks->values->min_a)
		return ;
	i = find_index_stack_a(stacks, stacks->values->min_a);
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
	do_moves_stack_a(stacks);
}

void	do_moves_stack_a(t_stacks *stacks)
{
	while (stacks->moves->ra-- != 0)
		ft_rotate(stacks, 'a');
	while (stacks->moves->rra-- != 0)
		ft_rev_rotate(stacks, 'a');
	ft_push(stacks, 'a');
}

int	find_index_stack_a(t_stacks *stacks, int nbr)
{
	t_stack_a	*head_a;
	int			size;
	int			i;

	i = 0;
	head_a = stacks->head_a;
	size = ft_listsize_a(stacks->head_a);
	while (i < size)
	{
		if (head_a->content == nbr)
			break;
		head_a = head_a->next;
		i++;
	}
	return (i);
}

// verificar se o primeiro valor da stack b vai ser passado para a posição correta
// se o valor a ser passado for menor que o MIN da stack A
//		posicione o menor valor da stack A no topo, e push A
// se o valor a ser passado for maior que o MAX da stack A
//		posicione o maior valor da stack A no sopé, e push A & rotate A
// senão, posicione o primeiro valor maior que o valor a ser passado no topo da stack A & push
// organizar a stack A em ordem crescente