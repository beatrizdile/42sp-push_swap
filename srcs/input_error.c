/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:19:18 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/08/17 17:31:54 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	input_error(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_printf("Error: missing argument.\n");
		exit(0);
	}
	check_integers(argc, argv);
	check_int_size(argc, argv);

	return (0);
}

void	check_integers(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		j = 0;
		while (j < (int)ft_strlen(argv[i]))
		{
			if (!ft_isdigit(argv[i][j]))
			{
				if (j == 0 && (argv[i][j] == '-' || argv[i][j] == '+'))
				{
					j++;
					continue ;
				}
				ft_printf("Error: some arguments aren't integers.\n");
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	check_int_size(int argc, char **argv)
{
	long	num;
	int		i;

	i = 1;
	while (i < argc)
	{
		num = ft_atol(argv[i]);
		if (num > INTMAX || num < INTMIN)
		{
			ft_printf("Error: some arguments are bigger than an integer.\n");
			exit(0);
		}
		i++;
	}
}

void	check_for_doubles(t_stack_a *head_a)
{
	t_stack_a	*tmp;
	t_stack_a	*ptr;
	int		i;
	int		num;

	i = 0;
	ptr = head_a;
	while (ptr != NULL)
	{
		tmp = ptr;
		num = tmp->content;
		tmp = tmp->next;
		while (tmp != NULL)
		{
			if (num == tmp->content)
			{
				ft_printf("Error: some arguments are duplicates.\n");
				ft_clearnodes(&head_a);
				exit(0);
			}
			tmp = tmp->next;
		}
		ptr = ptr->next;
	}
}
