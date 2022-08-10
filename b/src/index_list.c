#include "push_swap.h"

void set_index(t_list *root,t_list *tail)
{
    while (tail != root)
    {
        tail->index = -1;
        tail = tail ->prev;
    }
    root -> index = -1;
}

void index_list(t_list **root, t_list **tail)
{
    t_list *temp;
    int i;
    int k;

    set_index(*root,*tail);
    k = list_size(*root,*tail);
    i = 0;
    temp = find_smallest(*root,*tail);
    temp->index = i;
    while (k!=0)
    {
        temp = closest_list_num(*root,*tail,temp->num);
        if(temp != NULL)
        temp -> index = i+1;
        i++;
        k--;
    }
}

int absolute_val(int a)
{
    if(a < 0)
    a= a* -1;
    return a;
}

t_list *closest_list_num(t_list *root, t_list *tail, int pivot)
{
    int i;
    int fark;
    t_list *temp;

    i = 0;
    fark = INT_MAX;
    temp = NULL;
    while(tail != root)
    {
        if((fark > (absolute_val(pivot - tail->num)))&&(tail->index == -1))
        {
            fark = pivot - tail->num;
            temp = tail;
        }
        fark = absolute_val(fark);
        tail = tail->prev;
    }
    if((fark > (absolute_val(pivot - tail->num)))&&(tail->index == -1))
    {
        fark = pivot - tail->num;
        temp = tail;
    }
    fark = absolute_val(fark);
    return temp;
}

t_list* find_smallest(t_list *root, t_list *tail)
{
    t_list *temp;

    temp = tail;
    while (tail != root)
    {
        if (temp->num > tail->num){
            temp = tail;
        }
        tail = tail->prev;
    }
    if (temp->num > tail->num){
        temp = tail;
    }
    return temp; 
}