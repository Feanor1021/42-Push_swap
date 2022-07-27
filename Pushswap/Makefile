NAME := push_swap

ARC := libpush_swap.a

MAİN := src/push_swap.c

SRCS :=	src/ft_prchrstrng.c src/ft_printf.c src/ft_putnum_unum.c src/stack_crt_functions.c \
		src/rotates.c src/push_and_swap.c

OBJ := $(SRCS:%.c=%.o)

CC		 = clang
CFLAGS	 = -Wall -Wextra -Werror -I ./include

all: $(NAME)

$(NAME): $(ARC)
	$(CC) $(CFLAGS) $(MAİN) -o $(NAME) $(ARC)

$(ARC): $(OBJ)
	ar -rcs $(ARC) $(OBJ)

clean:
	@rm -f src/*.o

fclean: clean
	@rm -f $(ARC) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re