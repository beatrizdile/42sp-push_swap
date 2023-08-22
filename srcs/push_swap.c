/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:25:34 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/08/22 12:36:53 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	input_error(argc, argv);
	stacks.head_a = create_list_a(argc, argv);
	stacks.head_b = NULL;
	check_for_doubles(stacks.head_a);
	sorting(&stacks);
	ft_clearnodes_a(&stacks.head_a);
}

// program named push_swap that takes as an argument the stack
// a formatted as a list of integers. The first argument should be at the top of the
// stack (be careful about the order).

// The program must display the smallest list of instructions possible to sort the stack
// a, the smallest number being at the top.