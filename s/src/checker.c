#include "push_swap.h"

void	make_pros(t_stack *stack_a, t_stack *stack_b, char *s)
{
	if (s[0]=='s' && s[1]=='a' && s[2] == '\n')
		swap_s(stack_a,'a',0);
	else if (s[0]=='s' && s[1]=='b' && s[2] == '\n')
		swap_s(stack_b,'b',0);
	else if (s[0]=='s' && s[1]=='s' && s[2] == '\n')
		swap_both(stack_a,stack_b,0);
	else if (s[0]=='r' && s[1]=='a' && s[2] == '\n')
		shift_up_r(stack_a,'a',0);
	else if (s[0]=='r' && s[1]=='b' && s[2] == '\n')
		shift_up_r(stack_b,'b',0);
	else if (s[0]=='r' && s[1]=='r' && s[2] == 'r' &&  s[3] == '\n')
		shift_down_both(stack_a,stack_b,0);
	else if (s[0]=='r' && s[1]=='r' && s[2] == 'a' &&  s[3] == '\n')
		shift_down_rr(stack_a,'a',0);
	else if (s[0]=='r' && s[1]=='r' && s[2] == 'b' &&  s[3] == '\n')
		shift_down_rr(stack_b,'b',0);
	else if (s[0]=='r' && s[1]=='r' && s[2] == '\n')
		shift_up_both(stack_a,stack_b,0);
	else if (s[0]=='p' && s[1]=='a' && s[2] == '\n')
		push_a(stack_a,stack_b,0);
	else if (s[0]=='p' && s[1]=='b' && s[2] == '\n')
		push_b(stack_a,stack_b,0);
	else
		ft_error();
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
        exit(1);
    if(!stack_create_and_control(&stacks[0], argv, argc - 1))
        ft_error();
    read_lines(&stacks[0],&stacks[1]);
    if(is_sorted(stacks[0]) && stacks[1].size == 0)
        ft_printf("OK\n");
    else
        ft_printf("KO\n");
    free_all(&stacks[0],&stacks[1]);
    return 0;
}