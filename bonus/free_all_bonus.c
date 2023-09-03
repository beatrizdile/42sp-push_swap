/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 19:33:16 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/09/02 23:03:53 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_for_all_bonus(t_stacks *stacks)
{
	ft_clearnodes_a(&stacks->head_a);
	if (stacks->head_b != NULL)
		ft_clearnodes_b(&stacks->head_b);
}

void	print_error_and_exit_bonus(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	free_and_exit(t_stacks *stacks, char *cmd)
{
	free_for_all_bonus(stacks);
	free(cmd);
	print_error_and_exit_bonus();
}

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
			return (0);
		num = head_a->content;
	}
	return (1);
}
