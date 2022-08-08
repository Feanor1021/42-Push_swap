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
        tot+=tail->num;
        tail = tail ->prev;
        say++;
    }
    tot+=root->num;
    say++;
    ret = (tot) / say;
    return ret; 
}

int pivot_finder_b(t_list *root, t_list *tail, int index)
{
    int say;
    int ret;
    int tot;
    int i;
    
    tot = 0;
    say = 0;
    i = 0;
    while ((i < index )&&(root!=tail))
    {
        tot+=tail->num;
        tail = tail ->prev;
        say++;
        i--;
    }
    tot+=tail->num;
    say++;
    ret = (tot) / say;
    return ret; 
}

int farest_num(t_list *root, t_list *tail, int pivot, int biggest)
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
