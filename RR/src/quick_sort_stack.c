#include "push_swap.h"


void quick_sort_stack_b(t_list **root, t_list **tail, t_list **root2, t_list **tail2)
{
    int index;
    long pivot;
    int go_back;
    int size;

    size = list_size(*root2,*tail2);
    while(size > 0)
    {
        index=(*tail2)->index;
        go_back = 0;
        while (index )
        {
            pivot=pivot_finder_b(*tail2,*root2,index);
            if((pivot < (*tail2)->num )||(index == 1) || (go_back == index))
            {
                push_b(root,tail,root2,tail2);
                size --;
                if((*tail)->num > (*tail)->prev->num)
                    swap_s(tail,'a');
                index--;
                while (go_back)
                {
                    go_back--;
                    shift_up_r(root2,tail2,'b');
                }
            }
            else
            {
                shift_down_rr(root2,tail2,'b');
                go_back++;
            } 
        }
    }
}

void quick_sort_stack_a(t_list **root, t_list **tail, t_list **root2, t_list **tail2)
{
    int index;
    long pivot;
    int is_limit;
    int tail2in;

    is_limit = list_size(*root,*tail);
    if (list_size(*root,*tail)<=2)
    {
        if((*tail)->num > (*tail)->next->num)
            swap_s(tail,'a');
        return ;
    }
    tail2in=0;
    index=((*tail)->index) / 2;
            pivot=pivot_finder(*tail,*root);
    while (index && is_limit)
    {
        if(pivot > (*tail)->num)
        {
            push_a(root,tail,root2,tail2);
            if((*tail2)->num < (*tail2)->prev->num)
                swap_s(tail2,'b');
            is_limit = list_size(*root, *tail);
            index--;
            tail2in++;
        }
        else
        {
            shift_down_rr(root,tail,'a');
            is_limit--;
        }
    }
    (*tail)->index=list_size(*root,*tail);
    (*tail2)->index=tail2in;
    quick_sort_stack_a(root,tail,root2,tail2);
}

/*
void quick_sort_stack_a(t_list **root, t_list **tail, t_list **root2, t_list **tail2)
{
    long pivot;
    int is_limit;
    int r_num;
    int rr_num;

    is_limit = list_size(*root,*tail);
    while (is_limit>2)
    {
        pivot=pivot_finder(*tail,*root);
        r_num=find_min_r(*root,*tail,(farest_num(*root,*tail,pivot,find_biggest(*root,*tail))));
        rr_num=find_min_rr(*root,*tail,(farest_num(*root,*tail,pivot,find_biggest(*root,*tail))));
        if (r_num<rr_num)
            r_x_times(root,tail,rr_num);
        else
            rr_x_times(root,tail,r_num);
        push_a(root,tail,root2,tail2);
        is_limit--;
    }
    if((*tail)->num > (*tail)->next->num)
        swap_s(tail,'a');
}

void quick_sort_stack_b(t_list **root, t_list **tail, t_list **root2, t_list **tail2)
{
    int limit;

    limit = list_size (*root2,*tail2);
    while (limit>0)
    {
        push_b(root,tail,root2,tail2);
        limit--;
    }
}
*/
