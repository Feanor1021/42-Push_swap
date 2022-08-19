# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/14 16:12:33 by fyardimc          #+#    #+#              #
#    Updated: 2022/08/17 13:07:27 by fyardimc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

NAME_BONUS := checker

MAIN := main.o

MAIN2 := checker.o

SRCS :=	 stack_create_functions.c rotates.c swap_and_push.c push_swap_utils1.c push_swap_utils2.c\
		 push_swap_utils.c push_swap_utils3.c stack_create_frm_arg.c quick_sort_stack.c\
		 indexing_and_pivot.c min_rotate_functions.c quic_sort_stack_small.c

SRCSBONUS :=  ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c

OBJ := $(SRCS:%.c=%.o)

OBJB := $(SRCSBONUS:%.c=%.o)

CC		 = clang
CFLAGS	 = -Wall -Wextra -Werror

$(NAME): $(MAIN) $(OBJ)
	@make -C ./ft_printf
	$(CC) $(CFLAGS) $(OBJ) ./ft_printf/libftprintf.a $(MAIN) -o $(NAME)

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS):$(MAIN2) $(OBJ) $(OBJB)
	@make -C ./ft_printf
	$(CC) $(CFLAGS) $(OBJ) $(OBJB) ./ft_printf/libftprintf.a $(MAIN2) -o $(NAME_BONUS)

clean:
	@rm -f *.o ft_printf/*.o get_next_line/*.o
	@make -C ./ft_printf fclean

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	
re: fclean all

.PHONY: all clean fclean re bonus