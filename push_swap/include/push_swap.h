#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"
#include <limits.h>

typedef struct push
{
    long num;
    int index;
    struct push *next;
    struct push *prev;
}t_list;

//create functions
t_list  *create_stack_node( long num, t_list *tail);
int add_node_to_stack(t_list **root, t_list **tail, t_list *temp);
int stack_create_and_control(t_list **root, t_list **tail,char **argv,int argc);
t_list* pop_stack(t_list **root, t_list **tail);;
void print_list(t_list *root, t_list *tail);
int ft_isspace_srch_all(char *argv_sub);
int list_size(t_list *root, t_list *tail);

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

//indexing
void index_list(t_list **root, t_list **tail);
t_list *closest_list_num(t_list *root, t_list *tail, int pivot);
void set_index(t_list *root,t_list *tail);
t_list* find_smallest(t_list *root, t_list *tail);

//sorting algorithm
void sort_stack(t_list **root, t_list **tail, t_list **root2, t_list **tail2);
void arrange_chunk_b(t_list **root, t_list **tail, t_list **root2, t_list **tail2);
void sort_final(t_list **root, t_list **tail, t_list **root2, t_list **tail2);
//pivot finder
int pivot_finder(t_list *root, t_list *tail);


//min rotate functionw
int *find_min_path(t_list*root, t_list*tail, t_list *root2, t_list *tail2);
int find_min_rrb(t_list *root, t_list *tail, int index, int size);
int find_min_rotate(t_list *root, t_list *tail, int index, int size);
void r_x_times(t_list **root, t_list **tail,int num);
void rr_x_times(t_list **root, t_list **tail,int num);
int closest_index_b(t_list *root, t_list *tail, int index, int size);

//libft_functions
int	find_max_value(t_list *root, t_list *tail);
t_list*   ft_atol(const char *str, t_list * tail);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s1, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int absolute_val(int a);

#endif