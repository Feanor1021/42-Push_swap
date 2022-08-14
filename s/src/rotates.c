#include "push_swap.h"

void shift_up_r(t_stack *stacks,char id,int flag)
{
    if(stacks->root == NULL)
        return ;
    if(flag == 1)
    {
    if(id == 'a')
        ft_printf("ra\n");
    else
        ft_printf("rb\n");
    }
    stacks->tail=(stacks->tail)->prev;
    stacks->root=(stacks->root)->prev;
}

void shift_down_rr(t_stack *stacks,char id, int flag)
{
    if(stacks->root == NULL)
        return ;
    if(flag == 1)
    {
    if(id == 'a')
        ft_printf("rra\n");
    else
        ft_printf("rrb\n");
    }   
    stacks->tail=(stacks->tail)->next;
    stacks->root=(stacks->root)->next;
}

void shift_up_both(t_stack *stack_a,t_stack *stack_b, int flag)
{
    if(stack_a->root == NULL||stack_b->root == NULL)
        return ;
    if(flag == 1)
        ft_printf("rr\n");
    (stack_a->tail)=(stack_a->tail)->prev;
    (stack_a->root)=(stack_a->root)->prev;
    (stack_b->tail)=(stack_b->tail)->prev;
    (stack_b->root)=(stack_b->root)->prev;
}

void shift_down_both(t_stack *stack_a,t_stack *stack_b, int flag)
{
    if(stack_a->root == NULL||stack_b->root == NULL)
        return ;
    if(flag == 1)
        ft_printf("rrr\n");
    (stack_a->tail)=(stack_a->tail)->next;
    (stack_a->root)=(stack_a->root)->next;
    (stack_b->tail)=(stack_b->tail)->next;
    (stack_b->root)=(stack_b->root)->next;
}