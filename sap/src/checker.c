#include "push_swap.h"


void	make_pros(t_stack *stack_a, t_stack *stack_b, char *s)
{
	if (s[0] == 's' && s[1] == 'a')
		swap_s(&(stack_a->tail),stack_a->size,'a');
	else if (s[0] == 's' && s[1] == 'b')
		swap_s(&(stack_a->tail),stack_a->size,'a');
	else if (s[0] == 's' && s[1] == 's')
		swap_both(&(stack_a->tail),&(stack_b->tail),stack_a->size,stack_b->size);
	else if (s[0] == 'r' && s[1] == 'a')
		shift_up_r(stack_a,'a');
	else if (s[0] == 'r' && s[1] == 'b')
		shift_up_r(stack_b,'b');
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'r')
		shift_down_both(stack_a,stack_b);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'a')
		shift_down_rr(stack_a,'a');
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'b')
		shift_down_rr(stack_a,'b');
	else if (s[0] == 'r' && s[1] == 'r')
		shift_up_both(stack_a,stack_b);
	else if (s[0] == 'p' && s[1] == 'a')
		push_a(stack_a,stack_b);
	else if (s[0] == 'p' && s[1] == 'b')
		push_b(stack_a,stack_b);
}

void	read_lines(t_stack *s_a, t_stack *s_b)
{
	char	*tmp;

	while (1)
	{
		tmp = get_next_line(0);
		if (!tmp)
			break ;
		make_pros(s_a,s_b, tmp);
	}
}

int main(int argc, char **argv)
{
    t_stack stacks[2];

    stacks_init(&stacks[0],&stacks[1]);
    if(argc == 1)
        ft_error();
    if(!stack_create_and_control(&stacks[0], argv, argc - 1))
        ft_error();
    if(is_sorted(stacks[0]))
        exit(1);
    read_lines(&stacks[0],&stacks[1]);
    if(is_sorted(stacks[0]))
        ft_printf("OK\n");
    else
        ft_printf("KO\n");
    free_all(&stacks[0],&stacks[1]);
    return 0;
}