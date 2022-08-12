
#include <stdio.h>
#include <stdlib.h>

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
    int size_a;
    int size_b;
    int min_r;
    int min_rr;
}t_stack;
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

t_list *create_stack_node(long num, t_list *tail)
{
    t_list *node;
    node = (t_list*)malloc(sizeof(t_list));
    if(!node)
        return NULL;
    node->num=num;
    return node;
}
void printf_list(t_stack* stack)
{
    while(stack->root!=stack->tail)
    {
         printf("%ld\n",(stack->root)->num);  
        (stack->root)=(stack->root)->next;
    }
    printf("%ld\n",(stack->root)->num);  
}
int main(){
    t_stack stacks[2];
    stacks[0].root=NULL;
   stacks[0].tail=stacks[0].root;
    stacks[1].root2=NULL;
    stacks[1].tail2=stacks[1].root2;
    int i = 0;

    add_node_to_stack(&stacks[0].root,&stacks[0].tail,create_stack_node(12,stacks[0].tail)); 
    add_node_to_stack(&stacks[0].root,&stacks[0].tail,create_stack_node(122,stacks[0].tail)); 
    add_node_to_stack(&stacks[0].root,&stacks[0].tail,create_stack_node(132,stacks[0].tail));
    printf_list(&stacks[0]);
    printf("%ld\n",(stacks[0].root)->num); 
    

}