#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack stacks[1];

    stacks->root=NULL;
    stacks->tail=stacks->root;
    stacks->root2=NULL;
    stacks->tail2=stacks->root2;
    if(argc == 1)
        ft_printf("Error\n");
    else
    {
        if(!stack_create_and_control(&(stacks->root),&(stacks->tail), argv, argc - 1))
        {
            ft_printf("Error\n");
            return 0;
        }
    }
    index_list(&(stacks->root),&(stacks->tail));
    sort_stack(&(stacks->root),&(stacks->tail),&(stacks->root2),&(stacks->tail2));
    return 0;
}