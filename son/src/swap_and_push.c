#include "push_swap.h"


void push_a(t_list **root , t_list **tail, t_list **root2 , t_list **tail2)
{
    ft_printf("pa\n");
    add_node_to_stack(root2,tail2,pop_stack(root,tail));
}

void push_b(t_list **root , t_list **tail, t_list **root2 , t_list **tail2)
{
    ft_printf("pb\n");
    add_node_to_stack(root,tail,pop_stack(root2,tail2));
}

void swap_s(t_list **tail,char id)
{
    int num;

    if (id == 'a')
        ft_printf("sa\n");
    else
        ft_printf("ba\n");
    num = (*tail)->num;
    (*tail)->num = (*tail)->prev->num;
    (*tail)->prev->num = num;
}

void swap_both( t_list **tail, t_list **tail2)
{
    int num;

    ft_printf("ss\n");
    num = (*tail)->num;
    (*tail)->num = (*tail)->prev->num;
    (*tail)->prev->num = num;
    num = (*tail2)->num;
    (*tail2)->num = (*tail2)->prev->num;
    (*tail2)->prev->num = num;
}