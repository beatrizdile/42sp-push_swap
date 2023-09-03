/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:12:03 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/09/02 22:08:07 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define INTMAX 2147483647
# define INTMIN -2147483648

typedef struct t_stack_a
{
	int					content;
	struct t_stack_a	*next;
}						t_stack_a;

typedef struct t_stack_b
{
	int					content;
	struct t_stack_b	*next;
}						t_stack_b;

typedef struct t_stacks
{
	struct t_stack_a	*head_a;
	struct t_stack_b	*head_b;
	struct t_values		*values;
	struct t_moves		*moves;
	struct t_cheap		*cheap;
}						t_stacks;

typedef struct t_values
{
	int					max_a;
	int					min_a;
	int					max_b;
	int					min_b;
}						t_values;

typedef struct t_moves
{
	int					cost;
	int					sa;
	int					sb;
	int					ss;
	int					pa;
	int					pb;
	int					ra;
	int					rb;
	int					rr;
	int					rra;
	int					rrb;
	int					rrr;
}						t_moves;

typedef struct t_cheap
{
	int					cost;
	int					sa;
	int					sb;
	int					ss;
	int					pa;
	int					pb;
	int					ra;
	int					rb;
	int					rr;
	int					rra;
	int					rrb;
	int					rrr;
}						t_cheap;

// Error Checks
void		input_error(int argc, char **argv);
void		check_integers(int argc, char **argv);
void		check_int_size(int argc, char **argv);
void		check_for_doubles(t_stack_a *head_a);

// Linked List A
t_stack_a	*create_list_a(int argc, char **argv);
t_stack_a	*ft_newnode_a(int content);
void		ft_clearnodes_a(t_stack_a **lst);
int			ft_listsize_a(t_stack_a *lst);
t_stack_a	*ft_lstlast_a(t_stack_a *head_a);

// Linked List B
t_stack_b	*create_list_b(int argc, char **argv);
t_stack_b	*ft_newnode_b(int content);
void		ft_clearnodes_b(t_stack_b **lst);
int			ft_listsize_b(t_stack_b *head);

// Sort Four & Three & Two
void		sort_four(t_stacks *stacks);
void		sort_three(t_stacks *stacks, int flag);
void		sort_two(t_stacks *stacks);
void		identify_nums_three(t_stacks *stacks, int num1, int num2, int num3);

// Sort
void		sorting(t_stacks *stacks);
void		move_stack_a(t_stacks *stacks);

// Moves Push
void		ft_push(t_stacks *stacks, char ch);
void		ft_push_a(t_stacks *stacks);
void		ft_push_b(t_stacks *stacks);
void		ft_push_empty_b(t_stacks *stacks);
void		ft_last_push_a(t_stacks *stacks);

// Moves Swap
void		ft_swap(t_stacks *stacks, char ch);
void		ft_swap_a(t_stack_a *head_a, int print);
void		ft_swap_b(t_stack_b *head_b, int print);

// Moves Rotate
void		ft_rotate(t_stacks *stacks, char ch);
void		ft_rotate_a(t_stacks *stacks, t_stack_a *head_a, int print);
void		ft_rotate_b(t_stacks *stacks, t_stack_b *head_b, int print);

// Moves Rev Rotate
void		ft_rev_rotate(t_stacks *stacks, char ch);
void		ft_rev_rotate_a(t_stacks *stacks, t_stack_a *head_a, int print);
void		ft_rev_rotate_b(t_stacks *stacks, t_stack_b *head_b, int print);

// Move Cheapest
void		move_cheapest(t_stacks *stacks);
void		check_moves(t_stacks *stacks);
void		new_max_or_min_stack_b(t_stacks *stacks);
void		do_cheap_moves(t_stacks *stacks);

// Find Cheapest
void		new_max_or_min_stack_b(t_stacks *stacks);
int			find_index_stack_b(t_stacks *stacks, int nbr);
void		get_top_stack_a(t_stacks *stacks, t_stack_a *head_a, int i);
void		new_num_in_stack_b(t_stacks *stacks, int num);
int			search_num_stack_b(t_stacks *stacks, int nbr);
void		check_double_moves(t_stacks *stacks);
void		check_cost(t_stacks *stacks, int i);

// Move Back to Stack A
void		move_stack_a(t_stacks *stacks);
int			find_index_stack_a(t_stacks *stacks, int nbr);
int			search_stack_a(t_stacks *stacks, int nbr);
void		put_in_order(t_stacks *stacks);
void		new_min_stack_a(t_stacks *stacks);
void		new_max_stack_a(t_stacks *stacks);
void		new_elem_stack_a(t_stacks *stacks, t_stack_b *head_b);
void		do_moves_min_stack_a(t_stacks *stacks);
void		do_moves_max_stack_a(t_stacks *stacks);
void		do_moves_elem_stack_a(t_stacks *stacks);
void		do_moves_order(t_stacks *stacks);

// Check Max & Min B
void		check_max_min_b(t_stacks *stacks);
void		check_max_b(t_stacks *stacks, t_stack_b *head_b);
void		check_min_b(t_stacks *stacks, t_stack_b *head_b);

// Check Max & Min A
void		check_max_min_a(t_stacks *stacks);
void		check_max_a(t_stacks *stacks, t_stack_a *head_a);
void		check_min_a(t_stacks *stacks, t_stack_a *head_a);

// Print
void		print_error_and_exit(void);

// Lists Checks
int			check_list_order(t_stacks *stacks);

// Free All
void		free_for_all(t_stacks *stacks);

#endif