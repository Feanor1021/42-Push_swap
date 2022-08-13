#include "push_swap.h"


int main(int argc, char **argv)
{
    t_stack stacks[2];

    stacks_init(&stacks[0],&stacks[1]);
    if(argc == 1)
    {
        ft_printf("Error\n");
        return 0;
    }
    else
    {
        if(!stack_create_and_control(&stacks[0], argv, argc - 1))
        {
            ft_printf("Error\n");
            return 0;
        }
    }
    index_list(&stacks[0]);
    sort_stack(&stacks[0],&stacks[1]);
    return 0;
}