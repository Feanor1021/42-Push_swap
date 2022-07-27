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

#endif