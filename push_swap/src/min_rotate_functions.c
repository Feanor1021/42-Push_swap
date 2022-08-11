#include "push_swap.h"

int find_min_rrb(t_list *root, t_list *tail, int index, int size)
{
    int rr;
    t_list *temp;

    temp = tail;
    rr = 0;
    while((temp->index != index) && size!=0)
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
int find_min_rotate(t_list *root, t_list *tail, int index, int size)
{
    int r;
    t_list *temp;

    temp = tail;
    r = 0;
    while((temp->index != index) && size != 0)
    {
    temp=temp->prev;
    size--;
    }
    while(temp!=tail)
    {
        temp = temp -> next;
        r++;
    }
    return r;
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


int closest_index_b(t_list *root, t_list *tail, int index, int size)
{
    int fark;
    int flag;

    fark = INT_MAX;
    flag = 0;
    while(size)
    {
        if(tail!=NULL&&tail->index > index)
        {
            flag = 1;
            if((fark > (absolute_val(index - tail->index))))
            {
                fark = index - tail->index;
            }
            fark = absolute_val(fark);
        }
        if(tail!=NULL)
        tail = tail->prev;
        size--;
    }
    if (flag == 1)
    return index+fark;
    return find_max_value(root,tail);
}