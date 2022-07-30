#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"
#include <limits.h>

typedef struct push
{
    long num;
    struct push *next;
    struct push *prev;
}t_list;

//mandatory fuctions
t_list  *create_stack_node( long num);
int add_node_to_stack(t_list **root, t_list **tail, t_list *temp);
int stack_create_and_control(t_list **root, t_list **tail,char **argv);
t_list* pop_stack(t_list **root, t_list **tail);;
void print_list(t_list *root, t_list *tail);
int ft_isalnum_isspace(char *argv_sub);

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

//libft_functions
t_list*   ft_atol(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s1, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);


#endif