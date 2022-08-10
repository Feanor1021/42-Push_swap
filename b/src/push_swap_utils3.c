#include "push_swap.h"


int find_val_r(t_list *root, t_list *tail,int size)
{
    int temp;
    int i;

    i = 0;
    while (i<size)
    {
        tail = tail ->prev;
        i++;
    }
    return tail->num;
}

int find_val_rr(t_list *root, t_list *tail,int size)
{
    int temp;
    int i;

    i = 0;
    while (i<size)
    {
        tail = tail ->next;
        i++;
    }
    return tail->num;
}
