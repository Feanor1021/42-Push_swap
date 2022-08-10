#include "push_swap.h"

void	sort_three_args(t_data *a, t_data *b)
{
	if (a->array[a->size - 1] == 0)
	{
		if (a->array[a->size - 2] == 2)
		{
			push(a, b);
			if (a->array[a->size - 1] > a->array[a->size - 2])
				swap(a, 0);
			push(b, a);
		}
	}
	else if (a->array[a->size - 2] == 0)
	{
		if (a->array[a->size - 1] == 2)
			rotate(a, 0);
		else if (a->array[a->size - 1] == 1)
			swap(a, 0);
	}
	else if (a->array[a->size - 3] == 0)
	{
		if (a->array[a->size - 1] > a->array[a->size - 2])
			swap(a, 0);
		rev_rotate(a, 0);
	}
}

void	sort_four_args(t_data *a, t_data *b)
{
	int	i;

	i = 0;
	if (a->size == 4)
	{
		while (a->array[i] != 3)
			i++;
		if (i == 0)
			rev_rotate(a, 0);
		else
			while (++i < a->size)
				rotate(a, 0);
		push(a, b);
		sort_three_args(a, b);
		push(b, a);
		rotate(a, 0);
	}
	else
	{
		if (b->array[b->size - 1] > b->array[b->size - 2])
			swap(b, 0);
		sort_three_args(a, b);
		push(b, a);
		rotate(a, 0);
	}
}

void	sort_five_args_2(t_data *a, t_data *b, int i)
{
	if (i < 2)
	{
		while (--i >= 0)
		{
			rev_rotate(a, 0);
			if (a->array[a->size - 1] == 3)
				push(a, b);
		}
	}
	else
	{
		while (++i - 1 < a->size)
		{
			rotate(a, 0);
			if (a->array[a->size - 1] == 3)
				push(a, b);
		}
	}
}

void	sort_five_args(t_data *a, t_data *b)
{
	int	i;

	i = 0;
	if (a->array[a->size - 1] == 3)
		push(a, b);
	while (a->array[i] != 4)
		i++;
	i++;
	sort_five_args_2(a, b, i);
	push(a, b);
	sort_four_args(a, b);
	push(b, a);
	rotate(a, 0);
}

void	sort_smaller_list(t_data *a, t_data *b)
{
	if (a->size == 2)
	{
		if (a->array[a->size - 1] > a->array[a->size - 2])
			swap(a, 0);
	}
	else if (a->size == 3)
		sort_three_args(a, b);
	else if (a->size == 4)
		sort_four_args(a, b);
	else if (a->size == 5)
		sort_five_args(a, b);
}
