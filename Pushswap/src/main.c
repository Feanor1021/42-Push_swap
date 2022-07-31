#include "push_swap.h"

int main(int argc, char **argv)
{
    t_list *root;
    t_list *tail;

    root=NULL;
    tail=root;
    if(argc == 1)
        ft_printf("Error");
    else
    {
        if(!stack_create_and_control(&root, &tail, argv))
        {
            ft_printf("Error");
            return 0;
        }
    }
    print_list(root,tail);
    return 0;
}