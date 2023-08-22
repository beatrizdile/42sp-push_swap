/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:12:03 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/08/22 14:53:03 by bedos-sa         ###   ########.fr       */
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
}						t_stacks;

// Error Checks
void					input_error(int argc, char **argv);
void					check_integers(int argc, char **argv);
void					check_int_size(int argc, char **argv);
void					check_for_doubles(t_stack_a *head_a);

// Linked List A
t_stack_a				*create_list_a(int argc, char **argv);
t_stack_a				*ft_newnode_a(int content);
void					ft_clearnodes_a(t_stack_a **lst);
int						ft_listsize_a(t_stack_a *lst);

// Linked List B
t_stack_b				*create_list_b(int argc, char **argv);
t_stack_b				*ft_newnode_b(int content);
void					ft_clearnodes_b(t_stack_b **lst);
int						ft_listsize_b(t_stack_b *head);

// Sort
void					sorting(t_stacks *stacks);
void					sort_three(t_stacks *stacks);
void					identify_sequence(t_stacks *stacks);

// Moves Push
void					ft_push(t_stacks *stacks, char ch);
// void					ft_push_a(t_stacks *stacks);
void					ft_push_b(t_stacks *stacks);
void					ft_push_empty_b(t_stacks *stacks);

// Moves Swap
void					ft_swap(t_stacks *stacks, char ch);
void					ft_swap_a(t_stack_a *head_a);
void					ft_swap_b(t_stack_b *head_b);

// Moves Rotate
void					ft_rotate(t_stacks *stacks, char ch);
void					ft_rotate_a(t_stacks *stacks, t_stack_a *head_a);
void					ft_rotate_b(t_stacks *stacks, t_stack_b *head_b);

// Moves Rev Rotate
void					ft_rev_rotate(t_stacks *stacks, char ch);
void					ft_rev_rotate_a(t_stacks *stacks, t_stack_a *head_a);
void					ft_rev_rotate_b(t_stacks *stacks, t_stack_b *head_b);

// Print
void					print_linked_lists(t_stacks *stacks);
void					print_error_and_exit(void);

// Lists Checks
int						check_list_order(t_stacks *stacks);

#endif