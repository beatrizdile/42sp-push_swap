# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 10:33:46 by bedos-sa          #+#    #+#              #
#    Updated: 2023/08/30 15:43:36 by bedos-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g 
LIBFT = ./libft
LIBS = /include
RM = rm -f
FILES = srcs/push_swap.c \
		srcs/input_error.c \
		srcs/linked_list_a.c \
		srcs/linked_list_b.c \
		srcs/sorting.c \
		srcs/moves_swap.c \
		srcs/check_list.c \
		srcs/sort_three.c \
		srcs/moves_rotate.c \
		srcs/moves_rev_rotate.c \
		srcs/moves_push.c \
		srcs/find_cheapest.c \
		srcs/check_max_min_b.c \
		srcs/check_max_min_a.c \
		srcs/free_all.c \
		srcs/move_back.c \
		srcs/new_min_stack_a.c \
		srcs/new_max_stack_a.c
OBJS = $(FILES:.c=.o)
green = \033[32m
reset = \033[0m

all: $(NAME)
	@echo "$(green)SUCCESS!!!$(reset)"

%.o: %.c
	@$(CC) $(CFLAGS) -I.$(LIBS) -c $< -o $@

$(NAME): $(OBJS)
	make -C $(LIBFT)
	$(CC) $(OBJS) $(CFLAGS) $(LIBFT)/libft.a -O3 -g3 -L -lft -o $(NAME)

clean:
	make clean -C $(LIBFT)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFT)
	$(RM) $(NAME) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
