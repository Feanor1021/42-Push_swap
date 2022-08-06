#include "push_swap.h"

int find_min_r(t_list *root, t_list *tail, int num)
{
    int r;
    t_list *temp;

    temp = tail;
    r = 0;
    while(temp->num != num)
    temp=temp->prev;
    while(temp!=tail)
    {
        temp = temp -> next;
        r++;
    }
    return r;
}

int find_min_rr(t_list *root, t_list *tail, int num)
{
    int rr;
    t_list *temp;

    temp = tail;
    rr = 0;
    while(temp->num != num)
    temp=temp->prev;
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
    shift_up_r(root,tail,'a');
    i++;
    }
}

void r_x_times(t_list **root, t_list **tail,int num)
{
    int i;

    i = 0;
    while (i<num){
    shift_down_rr(root,tail,'a');
    i++;
    }
}