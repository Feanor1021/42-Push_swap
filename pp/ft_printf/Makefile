# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/14 16:12:28 by fyardimc          #+#    #+#              #
#    Updated: 2022/08/14 16:13:42 by fyardimc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

SRCS :=	ft_prchrstrng.c ft_printf.c ft_putnum_unum.c

OBJ := $(SRCS:%.c=%.o)

CC		 = clang
CFLAGS	 = -Wall -Wextra -Werror -I ./include

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean:
	@rm -f src/*.o

fclean: clean
	@rm -f $(NAME)
	
re: fclean all

.PHONY: all bonus clean fclean re