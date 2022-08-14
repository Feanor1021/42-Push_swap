#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "get_next_line.h"
#include <limits.h>

typedef struct push
{
    long num;
    int index;
    struct push *next;
    struct push *prev;
}t_list;

typedef struct stack
{
    t_list *root;
    t_list *tail;
    int size;
}t_stack;

//create functions
t_list  *create_stack_node( long num, t_list *tail);
int add_node_to_stack(t_stack* stacks, t_list *temp);
int  stack_create_and_control(t_stack *stack_a,char **argv, int argc);
t_list *pop_stack(t_stack *stacks);
int ft_isspace_srch_all(char *argv_sub);
int string_checker(t_stack *stack_a, char *argv);
int dublicated_check(t_stack stack);

void stacks_init(t_stack *stack_a, t_stack *stack_b);
void print_list(t_stack stack);
int list_size(t_stack stacks);

void	make_pros(t_stack *stack_a, t_stack *stack_b, char *s);

//rotates
void shift_up_r(t_stack *stacks,char id);
void shift_down_rr(t_stack *stacks,char id);
void shift_up_both(t_stack *stack_a,t_stack *stack_b);
void shift_down_both(t_stack *stack_a,t_stack *stack_b);
//pa pb
void push_a(t_stack* stack_a, t_stack* stack_b);
void push_b(t_stack* stack_a, t_stack* stack_b);
void swap_both( t_list **tail,t_list **tail2,int size1, int size2);
void swap_s(t_list **tail,int size, char id);

//indexing
void index_list(t_stack *stacks);
t_list *closest_list_num(t_stack stacks, long pivot);
void set_index(t_stack stacks);
t_list* find_smallest(t_stack stacks);

//sorting algorithm
void sort_stack(t_stack *stack_a, t_stack *stack_b);
void arrange_chunk_b(t_stack *stack_a, t_stack *stack_b);
void sort_final(t_stack *stacks);

void sort_small_stacks(t_stack *stack_a, t_stack *stack_b, int argc);
void tree_arg_sort(t_stack *s_a, t_stack *s_b);
void quad_arg_sort(t_stack *s_a, t_stack *s_b);
void penta_arg_sort(t_stack *s_a, t_stack *s_b);

//pivot finder
int pivot_finder(t_stack stacks);

//min rotate functionw
void find_min_path(t_stack stack_a, t_stack stack_b, int* index_a, int* index_b);
int find_min_rrb(t_stack stacks, int index, int size);
int find_min_rotate(t_stack stacks, int index, int size);
void r_x_times(t_stack *stack,int num);
void rr_x_times(t_stack *stack,int num);
int closest_index_b(t_stack stacks, int index, int size);

//libft_functions
int	find_max_value(t_stack stacks);
t_list*   ft_atol(const char *str, t_list * tail);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s1, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
long absolute_val(long a);
int is_sorted(t_stack stack_a);
//error
void ft_error();
//free function
void free_all(t_stack *stack_a, t_stack *stack_b);

#endif