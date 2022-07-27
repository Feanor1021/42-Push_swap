#include "include/push_swap.h"
#include "include/ft_printf.h"

int main()
{
    t_list *root=NULL;
    t_list *tail;
    tail=root;

    t_list *root2=NULL;
    t_list *tail2;
    tail2=root2;
    add_num_to_stack(&root,&tail,1);
    add_num_to_stack(&root,&tail,2);
    add_num_to_stack(&root,&tail,3);
    print_list(root,tail);
    add_node_to_stack(&root2,&tail2,pop_stack(&root,&tail));
    add_node_to_stack(&root2,&tail2,pop_stack(&root,&tail));
    add_node_to_stack(&root2,&tail2,pop_stack(&root,&tail));
    print_list(root2,tail2);
    print_list(root,tail);
}