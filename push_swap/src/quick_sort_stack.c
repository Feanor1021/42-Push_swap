#include "push_swap.h"


void find_min_path(t_stack stack_a, t_stack stack_b, int* index_a, int* index_b)
{
    int min;
    int a[2];
    int i[2];

    min = INT_MAX;
    i[0] = -1;
    i[1]= 0;
    while(stack_b.size>++i[0])
    {
        i[1]=find_min_rotate(stack_a,closest_index_b(stack_a,(stack_b.tail)->index,stack_a.size),stack_a.size);
        if(i[0]<(stack_b.size/ 2))
            a[0]=i[0];
        else
            a[0]=stack_b.size-i[0];
        if(i[1]<(stack_a.size/2))
            a[1]=i[1];
        else
            a[1]=stack_a.size-i[1];
        if(min>(a[0]+a[1]))
        {
            min=a[0]+a[1];
            *index_b=i[0];
            *index_a=i[1];
        }
        (stack_b.tail)=(stack_b.tail)->prev;
    }
}

void   sort_stack(t_stack *stack_a, t_stack *stack_b)
{
    int index_a;
    int index_b;

    arrange_chunk_b(stack_a, stack_b);
    while(stack_b->size)
    {
        find_min_path(*stack_a,*stack_b,&index_a,&index_b);
        if (index_a < (stack_a->size/ 2))
		    while (index_a-- > 0)
			    shift_up_r(stack_a,'a',1);
	    else
		    while (index_a++ < stack_a->size)
			    shift_down_rr(stack_a,'a',1);
	    if (index_b < (stack_b->size / 2))
		    while (index_b-- > 0)
			    shift_up_r(stack_b,'b',1);
	    else
		    while (index_b++ < stack_b->size)
			    shift_down_rr(stack_b,'b',1);
        push_a(stack_a,stack_b,1);
    }
    sort_final(stack_a);
}

void arrange_chunk_b(t_stack *stack_a, t_stack *stack_b)
{
    int pivot;
    int i;
    int size;

    pivot=pivot_finder(*stack_a);
    i = 0;
    size = stack_a->size;
    if(size < 3)
    {
        if(stack_a->size == 1)
            push_a(stack_a,stack_b,1);
        return;
    }
    while (size>i)
    {
        if(pivot >= (stack_a->tail)->index)
        {
            push_b(stack_a,stack_b,1);
        }
        else
            shift_up_r(stack_a,'a',1);
        i++;
    }
    arrange_chunk_b(stack_a,stack_b);
}

void sort_final(t_stack *stacks)
{
    int r_num;
    int rr_num;

    r_num = find_min_rotate(*stacks,0,stacks->size);
    rr_num = find_min_rrb(*stacks,0,stacks->size);
    if (r_num<rr_num)
    {
        r_x_times(stacks,r_num);
    }
    else if (r_num>=rr_num)
    {
        rr_x_times(stacks,rr_num);
    }
}

void sort_small_stacks(t_stack *stack_a, t_stack *stack_b, int argc)
{
    if(argc == 2)
    {
        if((stack_a->root)->num < (stack_a->tail)->num)
            swap_s(stack_a,'a',1);
    }
    else if(argc == 3)
        tree_arg_sort(stack_a, stack_b);
    else if(argc == 4)
        quad_arg_sort(stack_a, stack_b);
    else if (argc == 5)
        nonp_arg_sort(stack_a, stack_b);
}