#include "push_swap.h"

int main(int argc, char **argv)
{
    t_list *root;
    t_list *tail;
    t_list *root2;
    t_list *tail2;

    root=NULL;
    tail=root;
    root2=NULL;
    tail2=root2;
    if(argc == 1)
        ft_printf("Error\n");
    else
    {
        if(!stack_create_and_control(&root, &tail, argv))
        {
            ft_printf("Error\n");
            return 0;
        }
    }

  print_list(root,tail);
    quick_sort_stack_a(&root,&tail,&root2,&tail2);


        print_list(root,tail);
    printf("\n\n");
     print_list(root2,tail2);
    return 0;
}