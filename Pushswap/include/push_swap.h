#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "ft_printf.h"

typedef struct push
{
    int num;
    struct push *next;
    struct push *prev;
}t_list;


int add_num_to_stack(t_list **root, t_list **tail, int num);
int add_node_to_stack(t_list **root, t_list **tail, t_list *temp);
t_list* pop_stack(t_list **root, t_list **tail);
void print_list(t_list *root, t_list *tail);

//rotates
void shift_up_r(t_list **root, t_list **tail,char id);
void shift_down_rr(t_list **root, t_list **tail,char id);
void shift_up_both(t_list **root, t_list **tail,t_list **root2, t_list **tail2);
void shift_down_both(t_list **root, t_list **tail,t_list **root2, t_list **tail2);
//pa pb
void push_b(t_list **root , t_list **tail, t_list **root2 , t_list **tail2);
void push_a(t_list **root , t_list **tail, t_list **root2 , t_list **tail2);
void swap_both( t_list **tail, t_list **tail2);
void swap_s( t_list **tail,char id);

#endif