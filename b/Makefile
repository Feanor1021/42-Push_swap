NAME := push_swap

ARC := include/libpush_swap.a

MAİN := src/main.c

SRCS :=	src/ft_printf/ft_prchrstrng.c src/ft_printf/ft_printf.c src/ft_printf/ft_putnum_unum.c\
		 src/stack_create_functions.c src/rotates.c src/swap_and_push.c src/push_swap_utils1.c src/push_swap_utils2.c\
		 src/push_swap_utils.c src/stack_create_frm_arg.c src/quick_sort_stack.c src/pivot_finder.c src/push_swap_utils3.c\
		 src/index_list.c src/min_rotate_functions.c

OBJ := $(SRCS:%.c=%.o)

CC		 = clang
CFLAGS	 =  -I ./include

all: $(NAME)

$(NAME): $(ARC)
	$(CC) $(CFLAGS) $(MAİN) -o $(NAME) $(ARC)

$(ARC): $(OBJ)
	ar -rcs $(ARC) $(OBJ)

clean:
	@rm -f src/*.o src/ft_printf/*.o

fclean: clean
	@rm -f $(ARC) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re