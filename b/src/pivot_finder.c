#include "push_swap.h"
/*
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
*/

int pivot_finder(t_list *root, t_list *tail)
{
    int min;
    int ret;
    int max;
    int a;

    a=list_size(root,tail);
    min = INT_MAX;
    max = INT_MIN;
    while (a)
    {
        if(min > tail->index)
            min = tail->index;
       if(max < tail->index)
            max = tail->index;
        a--;
        tail = tail->prev;
    }
    ret = (max+min) / 2;
    return ret; 
}