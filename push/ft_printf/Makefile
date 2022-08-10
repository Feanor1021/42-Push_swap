# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saozcan <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 16:51:33 by saozcan           #+#    #+#              #
#    Updated: 2022/02/12 13:40:21 by saozcan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= ft_printf.c

OBJ		= $(SRC:.c=.o)

NAME	= libftprintf.a

CC		= @gcc

CFLAGS	= -Wall -Wextra -Werror -I.

RM		= @rm -rf

all:	$(NAME)

$(NAME):	$(OBJ)
			@ar rcs $(NAME) $(OBJ)

clean:	
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)
