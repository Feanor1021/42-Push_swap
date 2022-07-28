#include "push_swap.h"

void print_list(t_list *root, t_list *tail)
{
    while(tail!=root)
    {
        ft_printf("%d\n",(root)->num);
        root = (root)->next;
    }
    if(root!=NULL)
        ft_printf("%d\n",root->num);
}

int dublicated_check(t_list *root, t_list *tail)
{
    while(tail!=root)
    {
        if(tail->num == root->num)
            return 0;
        root=root->next;
    }
    return 1;
}

int stack_create_and_control(t_list **root, t_list **tail,char **argv)
{
    int i;

    i = 1;
    while(argv[i])
    {
        
        if(!add_node_to_stack(&(*root),&(*tail),ft_atol(argv[i])))
        {
            return 0;
        }
        if((*root!=*tail)&&(!dublicated_check(*root, *tail)))
            return 0;
        i++;
    }
    return 1;
}