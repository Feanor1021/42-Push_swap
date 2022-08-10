#include "push_swap.h"

int find_min_ra(t_list *root, t_list *tail, int index, int size)
{
    int r;
    t_list *temp;

    temp = tail;
    r = 0;
        if(tail->index == index)
    {
        temp=temp->prev;
        size--;
    }
    while((temp->index >= index)&&size != 0)
    {
    temp=temp->prev;
    size --;
    }
    while(temp!=tail)
    {
        temp = temp -> next;
        r++;
    }
    return r;
}

int find_min_rra(t_list *root, t_list *tail, int index, int size)
{
    int rr;
    t_list *temp;

    temp = tail;
    rr = 0;
    if(tail->index == index)
    {
        temp=temp->next;
        size--;
    }
    while((temp->index >= index) && size!=0)
    {
        temp=temp->next;
        size--;
    }
    while(temp!=tail)
    {
        temp = temp -> prev;
        rr++;
    }
    return rr;
}

void rr_x_times(t_list **root, t_list **tail,int num)
{
    int i;

    i = 0;
    while (i<num){
    shift_down_rr(root,tail,'a');
    i++;
    }
}

void r_x_times(t_list **root, t_list **tail,int num)
{
    int i;

    i = 0;
    while (i<num){
    shift_up_r(root,tail,'a');
    i++;
    }
}