/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:46:08 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/08/22 12:26:46 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_list_order(t_stacks *stacks)
{
	t_stack_a	*head_a;
	int			num;
	int			i;

	i = 1;
	head_a = stacks->head_a;
	num = head_a->content;
	while (i++ < ft_listsize_a(stacks->head_a))
	{
		head_a = head_a->next;
		if (num > head_a->content)
		{
			ft_printf("Not sorted.\n");
			return (0);
		}
		num = head_a->content;
	}
	ft_printf("Sorted.\n");
	return (1);
}
