#include "push_swap.h"


void quick_sort_stack_a(t_list **root, t_list **tail, t_list **root2, t_list **tail2)
{
    int index;
    long pivot;

    if ((*tail)->index <= 2)
    {
        if((*tail)->num > (*tail)->next->num)
            swap_s(tail,'a');
        return ;
    }
    index=((*tail)->index) / 2;
    pivot=(*tail)->num;
    while (index)
    {
        if(pivot > (*tail)->num)
        {
            push_a(root,tail,root2,tail2);
            index--;
        }
        else
            shift_down_rr(root,tail,'a');
    }
    (*tail)->index=(*tail)->index/2;
    (*tail2)->index=(*tail)->index;
    quick_sort_stack_a(root,tail,root2,tail2);
}

int is_biggest(t_list *tail2, t_list* root2, long pivot,int size)
{
    int flag;

    if(size == 1)
        return 1;
    flag = 0;
    tail2=tail2->next;
    while (tail2 != root2 &&size>0)
    {
        if(pivot < tail2->num)
            flag = 1;
        tail2 = tail2->next;   
        size--;
    }
    if(flag == 0 || tail2->num > pivot)
        return 0;
    return 1;
}

void quick_sort_stack_b(t_list **root, t_list **tail, t_list **root2, t_list **tail2)
{
    int index;
    long pivot;
    int go_back;

    while(*tail2!=*root2){
        index=(*tail2)->index -1 ;
        pivot=(*tail2)->num;
        go_back = 0;
        *tail2=(*tail2)->prev;
        while (index != 0 && (*tail2 != *root2))
        {
            if((pivot < (*tail2)->num )||(index == 1) || (go_back == index-1))
            {
                push_b(root,tail,root2,tail2);
                if((*tail)->num > (*tail)->prev->num)
                    swap_s(tail,'a');
                index--;
                while (go_back){
                    go_back--;
                    shift_up_r(root2,tail2,'b');}
            }
            else
            {
                shift_down_rr(root2,tail2,'b');
                go_back++;
            } 
        }
    }
    push_b(root,tail,root2,tail2);
}