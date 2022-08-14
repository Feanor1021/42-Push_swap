NAME := push_swap

NAME_BONUS := checker

ARC := include/libpush_swap.a

MAİN := src/main.c

SRCS :=	src/ft_printf/ft_prchrstrng.c src/ft_printf/ft_printf.c src/ft_printf/ft_putnum_unum.c\
		 src/stack_create_functions.c src/rotates.c src/swap_and_push.c src/push_swap_utils1.c src/push_swap_utils2.c\
		 src/push_swap_utils.c src/push_swap_utils3.c src/stack_create_frm_arg.c src/quick_sort_stack.c\
		 src/indexing_and_pivot.c src/min_rotate_functions.c src/quic_sort_stack_small.c

SRCSBONUS := src/checker.c src/get_next_line/get_next_line.c src/get_next_line/get_next_line_utils.c

OBJ := $(SRCS:%.c=%.o)

CC		 = clang
CFLAGS	 =  -I ./include

all: $(NAME) $(MAİN)

$(NAME): $(ARC)
	$(CC) $(CFLAGS) $(MAİN) -o $(NAME) $(ARC)

$(ARC): $(OBJ)
	ar -rcs $(ARC) $(OBJ)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(ARC)
	$(CC) $(CFLAGS) $(SRCS) $(SRCSBONUS) -o $(NAME_BONUS) $(ARC)

clean:
	@rm -f src/*.o src/ft_printf/*.o src/get_next_line/*.o

fclean: clean
	@rm -f $(ARC) $(NAME) $(NAME_BONUS)
	
re: fclean all

.PHONY: all clean fclean re bonus