# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 10:33:46 by bedos-sa          #+#    #+#              #
#    Updated: 2023/09/02 22:14:06 by bedos-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath %.c srcs
vpath %.c bonus

NAME = push_swap
NAME_BONUS = checker

CC = cc
FLAGS = -O3 -g3 -L -lft
CFLAGS = -Wall -Wextra -Werror -g 

LIBFT = ./libft
LIBS = /include

RM = rm -f
FILES = push_swap.c \
		input_error.c \
		linked_list_a.c \
		linked_list_b.c \
		sorting.c \
		moves_swap.c \
		check_list.c \
		sort_four.c \
		sort_three.c \
		sort_two.c \
		moves_rotate.c \
		moves_rev_rotate.c \
		moves_push.c \
		find_cheapest.c \
		check_max_min_b.c \
		check_max_min_a.c \
		checks_cheapest.c \
		free_all.c \
		move_back.c \
		new_min_stack_a.c \
		new_max_stack_a.c \
		new_elem_stack_a.c \
		new_in_stack_b.c

FILES_BONUS = checker_bonus.c \
			  input_error_bonus.c \
			  linked_list_a_bonus.c \
			  free_all_bonus.c \
			  linked_list_b_bonus.c \
			  moves_push_bonus.c \
			  moves_rev_rotate_bonus.c \
			  moves_rotate_bonus.c \
			  moves_swap_bonus.c
OBJ_DIR = build

OBJS = $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))
OBJS_BONUS = $(addprefix $(OBJ_DIR)/, $(FILES_BONUS:.c=.o))

green = \033[32m
reset = \033[0m

all: $(NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I.$(LIBS) -c $< -o $@

$(NAME): $(OBJS)
	make -C $(LIBFT)
	$(CC) $(OBJS) $(CFLAGS) $(LIBFT)/libft.a -O3 -g3 -L -lft -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	make -C $(LIBFT)
	$(CC) $(OBJS_BONUS) $(CFLAGS) $(LIBFT)/libft.a $(FLAGS) -o $(NAME_BONUS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	make clean -C $(LIBFT)
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	make fclean -C $(LIBFT)
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re bonus re_bonus
