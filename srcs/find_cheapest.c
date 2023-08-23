/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:29:24 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/08/23 17:03:48 by bedos-sa         ###   ########.fr       */
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
	// check_moves(stacks);
}

void	check_moves(t_stacks *stacks)
{
	int	i;
	int	size;

	i = 0;
	size = ft_listsize_a(stacks->head_a);
	while (i++ < size)
	{
		
	}
}


// primeiro check se o valor a ser passado de A para B é maior que o MAX de B ou
// menor que o MIN de B
// Se sim, precisamos colocar ele acima do MAX de B
//		devemos calcular quantos movimentos são precisos para deixar o MAX de B
//		no topo da stack + quanto custa mover elemento para o topo da stack A + push
// Se não, colocar em algum lugar na stack
