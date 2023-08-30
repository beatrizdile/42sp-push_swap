/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:59:02 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/08/30 11:52:02 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_for_all(t_stacks *stacks)
{
	ft_clearnodes_a(&stacks->head_a);
	ft_clearnodes_b(&stacks->head_b);
	free(stacks->values);
	free(stacks->moves);
	free(stacks->cheap);
}
