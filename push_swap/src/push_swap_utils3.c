#include "push_swap.h"


int	find_max_value(t_list *root, t_list *tail)
{
	int	i;
	int	max;
    int size;
	int	index;

	i = 0;
    size = list_size(root,tail);
	max = INT_MIN;
	while (i < size)
	{
		if (tail->index > max)
		{
			max = tail->index;
			index = tail->index;
		}
        tail = tail->next;
		i++;
	}
	return (index);
}

t_list* find_smallest(t_list *root, t_list *tail)
{
    t_list *temp;

    temp = tail;
    while (tail != root)
    {
        if (temp->num > tail->num){
            temp = tail;
        }
        tail = tail->prev;
    }
    if (temp->num > tail->num){
        temp = tail;
    }
    return temp; 
}

int absolute_val(int a)
{
    if(a < 0)
    a= a* -1;
    return a;
}