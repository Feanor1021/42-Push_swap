#include "push_swap.h"

void shift_up_r(t_list **root, t_list **tail,char id)
{
    if(id == 'a')
        ft_printf("ra\n");
    else
        ft_printf("rb\n");
    *tail=(*tail)->prev;
    (*tail)->index=(*tail)->next->index;
    *root=(*root)->prev;
}

void shift_down_rr(t_list **root, t_list **tail,char id)
{
    if(id == 'a')
        ft_printf("rra\n");
    else
        ft_printf("rrb\n");
    *tail=(*tail)->next;
    (*tail)->index=(*tail)->prev->index;
    *root=(*root)->next;
}

void shift_up_both(t_list **root, t_list **tail,t_list **root2, t_list **tail2)
{
    ft_printf("rr\n");
    *tail=(*tail)->prev;
    *root=(*root)->prev;
    *tail2=(*tail2)->prev;
    *root2=(*root2)->prev;
}

void shift_down_both(t_list **root, t_list **tail,t_list **root2, t_list **tail2)
{
    ft_printf("rrr\n");
    *tail=(*tail)->next;
    *root=(*root)->next;
    *tail2=(*tail2)->next;
    *root2=(*root2)->next;
}