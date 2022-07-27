#include "push_swap.h"

int add_node_to_stack(t_list **root, t_list **tail, t_list *temp)
{
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
int add_num_to_stack(t_list **root, t_list **tail, int num)
{
    if(*root == NULL)
    {
        *root = (t_list*)malloc(sizeof(t_list));
        if(!*root)
            return 0;
        (*root)->num=num;
        (*root)->next=*root;
        (*root)->prev=*root;
        *tail=*root;
    }
    else
    {
        t_list *temp;
        temp = (t_list*)malloc(sizeof(t_list));
        if(!temp)
            return 0;
        temp->num=num;
        add_node_to_stack(root,tail,temp);
    }
    return 1;
}
t_list* pop_stack(t_list **root, t_list **tail)
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

void print_list(t_list *root, t_list *tail)
{
    while(tail!=root)
    {
        ft_printf("%d\n",(tail)->num);
        tail = (tail)->prev;
    }
    if(root!=NULL)
        ft_printf("%d\n",root->num);
}