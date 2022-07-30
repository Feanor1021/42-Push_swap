#include "push_swap.h"

int add_node_to_stack(t_list **root, t_list **tail, t_list *temp)
{
    if(temp == NULL)
    {
        return 0;
    }
    if(*root == NULL)
    {
        *root = temp;
        (*root)->next=*root;
        (*root)->prev=*root;
        *tail=*root;
    }
    else
    {
        (*tail)->next=temp;
        (*tail)->next->prev=(*tail);
        (*tail)=(*tail)->next;
        (*tail)->next=*root;
        (*root)->prev=*tail;
    }
    return 1;
}

t_list *create_stack_node(long num)
{
    t_list *node;
    node = (t_list*)malloc(sizeof(t_list));
    if(!node)
        return NULL;
    node->num=num;
    return node;
}
t_list *pop_stack(t_list **root, t_list **tail)
{
    t_list* temp;

    if(root==NULL)
        return NULL;
    else if((*root)->next==*root)
    {
        temp=*root;
        *root=NULL;
        *tail=NULL;
        return temp;
    }
    else
    {
        temp=*tail;
        *tail=(*tail)->prev;
        (*tail)->next=*root;
        (*root)->prev=*tail;
        return temp;
    }
    return NULL;
}
