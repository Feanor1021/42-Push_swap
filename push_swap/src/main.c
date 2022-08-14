#include "push_swap.h"

//swapleri güncelle
// checker yazı yazmamalı onun için flag gönder ra v.sye yazmasın.
//norm düzenle
//pushla geç
//gg

int main(int argc, char **argv)
{
    t_stack stacks[2];

    stacks_init(&stacks[0],&stacks[1]);
    if(argc == 1)
        exit(1);
    if(!stack_create_and_control(&stacks[0], argv, argc - 1))
        ft_error();
    if(is_sorted(stacks[0]))
        exit(1);
   if((argc-1) > 5)
    {
        index_list(&stacks[0]);
        sort_stack(&stacks[0],&stacks[1]);
    }
    else
        sort_small_stacks(&stacks[0],&stacks[1],argc -1);
    free_all(&stacks[0],&stacks[1]);
    return 0;
}