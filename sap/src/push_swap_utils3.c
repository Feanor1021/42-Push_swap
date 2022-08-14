#include "push_swap.h"


int	find_max_value(t_stack stacks)
{
	int	i;
	int	max;
    int size;
	int	index;

	i = 0;
    size = list_size(stacks);
	max = INT_MIN;
	while (i < size)
	{
		if ((stacks.tail)->index > max)
		{
			max = (stacks.tail)->index;
			index = (stacks.tail)->index;
		}
        (stacks.tail) = (stacks.tail)->next;
		i++;
	}
	return (index);
}

t_list* find_smallest(t_stack stacks)
{
    t_list *temp;

    temp = stacks.tail;
    while (stacks.tail != stacks.root)
    {
        if (temp->num > (stacks.tail)->num){
            temp = stacks.tail;
        }
        stacks.tail = (stacks.tail)->prev;
    }
    if (temp->num > (stacks.tail)->num){
        temp = stacks.tail;
    }
    return temp; 
}

long absolute_val(long a)
{
    if(a < 0)
    a= a* -1;
    return a;
}

void ft_error()
{
	ft_printf("Error\n");
	exit(1);
}

void free_all(t_stack *stack_a, t_stack *stack_b)
{
    t_list *temp;

    if(stack_a->root != NULL)
    {
        while(stack_a->tail != stack_b->root)
        {
            temp = pop_stack(stack_a);
            free(temp);
        }
        if(stack_a->tail == stack_a->root)
        free(stack_a->root);
    }
    if(stack_b->root != NULL)
    {
        while(stack_a->tail != stack_b->root)
        {
            temp = pop_stack(stack_b);
            free(temp);
        }
        if(stack_b->tail == stack_b->root)
         free(stack_b->root);
    }
}