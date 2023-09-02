/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:59:54 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/09/02 16:22:46 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_stacks *stacks)
{
	if (check_list_order(stacks))
		return ;
	if (ft_listsize_a(stacks->head_a) == 2)
		sort_two(stacks);
	else if (ft_listsize_a(stacks->head_a) == 3)
		sort_three(stacks, 1);
	else if (ft_listsize_a(stacks->head_a) == 4)
		sort_four(stacks);
	ft_push(stacks, 'b');
	ft_push(stacks, 'b');
	move_cheapest(stacks);
	sort_three(stacks, 0);
	move_stack_a(stacks);
}
