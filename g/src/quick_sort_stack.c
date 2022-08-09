#include "push_swap.h"
int find_min_rb(t_list *root, t_list *tail, int index, int size)
{
    int r;
    t_list *temp;

    temp = tail;
    r = 0;
    while((temp->index != index) && size != 0)
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
int closest_index_b(t_list *root, t_list *tail, int index, int size)
{
    int fark;

    fark = INT_MAX;
    while(size)
    {
        if(tail!=NULL&&tail->index > index)
        {
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
    return index+fark;
}

void quick_sort_stack_b(t_list **root, t_list **tail, t_list **root2, t_list **tail2)
{
    int is_size;
    int r_num;
    int rr_num;
    int cls_index;

    is_size=list_size(*root2,*tail2);
    while(is_size && tail2 != root2)
    {
        if((*tail2)->index < (*tail2)->prev->index)
            swap_s(tail2,'b');
        if((*tail)->index > (*tail2)->index)
            push_b(root,tail,root2,tail2);
        else{
        cls_index = closest_index_b(*root,*tail,(*tail2)->index,list_size(*root,*tail));
        r_num = find_min_rb(*root,*tail,cls_index,list_size(*root,*tail));
        rr_num = find_min_rrb(*root,*tail,cls_index,list_size(*root,*tail));
        
        if (cls_index == 1)
        {

        }
        else if (r_num<rr_num)
        {
            r_x_times(root,tail,r_num);
            push_b(root,tail,root2,tail2);
            rr_x_times(root,tail,r_num);
        }
        else if (r_num>=rr_num)
        {
            rr_x_times(root,tail,rr_num);
            push_b(root,tail,root2,tail2);
            r_x_times(root,tail,rr_num);
        }
        }
        is_size--;
    }
}

void quick_sort_stack_a(t_list **root, t_list **tail, t_list **root2, t_list **tail2)
{
    int pivot;
    int is_size;
    int r_num;
    int rr_num;

    is_size = list_size(*root,*tail);
    while (is_size>2)
    {
        pivot=pivot_finder(*root,*tail);
        r_num = find_min_ra(*root,*tail,pivot,is_size);
        rr_num = find_min_rra(*root,*tail,pivot,is_size);
        if (r_num<rr_num)
            r_x_times(root,tail,r_num);
        else if (r_num>rr_num)
            rr_x_times(root,tail,rr_num);
        else if (find_val_r(*root,*tail,r_num)>find_val_rr(*root,*tail,rr_num))
            rr_x_times(root,tail,rr_num);
        else if(find_val_r(*root,*tail,r_num)<find_val_rr(*root,*tail,rr_num))
            r_x_times(root,tail,r_num);
        else if (find_val_r(*root,*tail,r_num) == find_val_rr(*root,*tail,rr_num))
            rr_x_times(root,tail,rr_num);
        push_a(root,tail,root2,tail2);
        is_size--;
    }
    if((*root)->index < (*tail)->index)
        swap_s(tail,'a');
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
/*
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
}*/