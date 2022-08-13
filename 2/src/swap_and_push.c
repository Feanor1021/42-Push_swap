#include "push_swap.h"


void push_b(t_stack* stack_a, t_stack* stack_b)
{
      if(stack_a->size == 0)
        return;
    ft_printf("pb\n");
    stack_a->size--;
    stack_b->size++;
    if(!add_node_to_stack(stack_b,pop_stack(stack_a)))
        return ;
}

void push_a(t_stack* stack_a, t_stack* stack_b)
{
    if(stack_b->size == 0)
        return;
    ft_printf("pa\n");
    stack_a->size++;
    stack_b->size--;
    if(!add_node_to_stack(stack_a,pop_stack(stack_b)))
        return ;
}

void swap_s(t_list **tail, int size, char id)
{
    int num;
    int index;

    if(*tail == NULL||size == 1)
        return ;
    if (id == 'a')
        ft_printf("sa\n");
    else
        ft_printf("sb\n");
    num = (*tail)->num;
    index = (*tail)->index;
    (*tail)->num = (*tail)->prev->num;
    (*tail)->index = (*tail)->prev->index;
    (*tail)->prev->num = num;
    (*tail)->prev->index = index;
}

void swap_both( t_list **tail, t_list **tail2, int size1, int size2)
{
    int num;
    int index;

    if(*tail == NULL || *tail2 == NULL || size1 == 1 || size2 == 1)
        return ;
    ft_printf("ss\n");
    num = (*tail)->num;
    index = (*tail)->index;
    (*tail)->num = (*tail)->prev->num;
    (*tail)->index = (*tail)->prev->index;
    (*tail)->prev->num = num;
    (*tail)->prev->index = index;
    num = (*tail2)->num;
    index = (*tail2)->index;
    (*tail2)->num = (*tail2)->prev->num;
    (*tail2)->index = (*tail2)->prev->index;
    (*tail2)->prev->num = num;
    (*tail2)->prev->index = index;
}