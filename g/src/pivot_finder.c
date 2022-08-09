#include "push_swap.h"

int pivot_finder(t_list *root, t_list *tail)
{
    int say;
    int ret;
    int tot;

    tot = 0;
    say = 0;
    while (tail != root)
    {
        tot+=tail->index;
        tail = tail ->prev;
        say++;
    }
    tot+=root->index;
    say++;
    ret = (tot) / say;
    return ret; 
}