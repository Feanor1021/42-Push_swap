#include "push_swap.h"

int pivot_finder_a(t_list *tail, t_list *root)
{
    int enb;
    int enk;
    int ret;

    enb = tail->num;
    enk = tail->num;
    while (tail != root)
    {
        if (enb < tail->num)
            enb = tail->num;
        if(enk > tail->num)
            enk = tail->num;
        tail = tail->prev;
    }
    if (enb < tail->num)
        enb = tail->num;
    if(enk > tail->num)
        enk = tail->num;
    ret = (enb + enk) / 2;
    return ret; 
}

int closest_num(t_list *root, t_list *tail, int pivot, int biggest)
{
    int i;
    int fark;

    i = 0;
    fark = INT_MIN;
    if(fark<0)
        fark*=-1;
    while(tail != root)
    {
        if((fark < (pivot - tail->num))&&(tail->num != biggest))
        fark = pivot - tail->num;
        if(fark<0)
        fark*=-1;
        tail = tail->prev;
    }
    if((fark < (pivot - tail->num))&&(tail->num != biggest))
    fark = pivot - tail->num;
    if(fark<0)
    fark*=-1;
    return (pivot - fark);
}

int find_biggest(t_list *root, t_list *tail)
{
    int enb;

    enb = tail->num;
    while (tail != root)
    {
        if (enb < tail->num)
            enb = tail->num;
        tail = tail->prev;
    }
    if (enb < tail->num)
        enb = tail->num;
    return enb; 
}
