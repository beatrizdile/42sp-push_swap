/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:25:34 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/08/23 15:52:32 by bedos-sa         ###   ########.fr       */
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
	ft_clearnodes_b(&stacks.head_b);
	free(stacks.values);
}

// ./push_swap 5 2 7 1 6 3 9 4 8