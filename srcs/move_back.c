/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:53:24 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/08/30 16:54:28 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_stack_a(t_stacks *stacks)
{
	t_stack_b	*head_b;
	// int			size;
	// int			i;
	
	// i = 0;
	// size = ft_listsize_b(stacks->head_b);
	head_b = stacks->head_b;
	// while (i++ < size)
	// {
		check_max_min_a(stacks);
		if (head_b->content < stacks->values->min_a)
			new_min_stack_a(stacks);
		else if (head_b->content > stacks->values->max_a)
			new_max_stack_a(stacks);
		else
			new_elem_stack_a(stacks, head_b);
		head_b = head_b->next;
	// }
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