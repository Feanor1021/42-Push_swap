#include "push_swap.h"


void tree_arg_sort(t_stack *s_a, t_stack *s_b)
{
    index_list(s_a);
    if(is_sorted(*s_a))
        return ;
    if((s_a->root)->index == 1 && (s_a->root)->next->index == 2 &&((s_a->tail)->index)== 0)
    {
        shift_down_rr(s_a,'a');
        swap_s(&(s_a->tail),3,'a');
    }
    else if ((s_a->root)->index == 2 && (s_a->root)->next->index == 0 &&((s_a->tail)->index)== 1)
        swap_s(&(s_a->tail),3,'a');
    else if((s_a->root)->index == 0 && (s_a->root)->next->index == 2 &&((s_a->tail)->index)== 1)
        shift_down_rr(s_a,'a');
    else if((s_a->root)->index == 0 && (s_a->root)->next->index == 1 &&((s_a->tail)->index)== 2)
    {
        swap_s(&(s_a->tail),3,'a');
        shift_down_rr(s_a,'a');
    }
    else
        shift_up_r(s_a,'a');
}

void quad_arg_sort(t_stack *s_a, t_stack *s_b)
{
    int index_a;

    index_list(s_a);
    if(is_sorted(*s_a))
        return ;
    index_a=find_min_rotate(*s_a,0,s_a->size);
    if (index_a < (s_a->size/ 2))
	    while (index_a-- > 0)
		    shift_up_r(s_a,'a');
	else
		while (index_a++ < s_a->size)
		    shift_down_rr(s_a,'a');
    push_b(s_a,s_b);
    tree_arg_sort(s_a,s_b);
    push_a(s_a,s_b);
}

void penta_arg_sort(t_stack *s_a, t_stack *s_b)
{
    int index_a;
    index_list(s_a);
    index_a=find_min_rotate(*s_a,0,s_a->size);
    if (index_a < (s_a->size/ 2))
	    while (index_a-- > 0)
		    shift_up_r(s_a,'a');
	else
		while (index_a++ < s_a->size)
		    shift_down_rr(s_a,'a');
    push_b(s_a,s_b);
    quad_arg_sort(s_a,s_b);
    push_a(s_a,s_b);   
}