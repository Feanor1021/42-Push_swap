/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:46:11 by fyardimc          #+#    #+#             */
/*   Updated: 2022/08/17 14:13:23 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_value(t_stack stacks)
{
	int	i;
	int	max;
	int	size;
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

t_list	*find_smallest(t_stack stacks)
{
	t_list	*temp;

	temp = stacks.tail;
	while (stacks.tail != stacks.root)
	{
		if (temp->num > (stacks.tail)->num)
		{
			temp = stacks.tail;
		}
		stacks.tail = (stacks.tail)->prev;
	}
	if (temp->num > (stacks.tail)->num)
	{
		temp = stacks.tail;
	}
	return (temp);
}

long	absolute_val(long a)
{
	if (a < 0)
		a = a * -1;
	return (a);
}

void	ft_error(int flag, t_stack *stack_a, t_stack *stack_b, char **argv)
{
	write(flag, "Error\n", ft_strlen("Error\n"));
	free_all(stack_a, stack_b);
	free_split(argv);
	exit(1);
}

void	free_all(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	if (stack_a->root != NULL)
	{
		while (stack_a->size > i)
		{
			free(pop_stack(stack_a));
			i++;
		}
	}
	i = 0;
	if (stack_b->root != NULL)
	{
		while (stack_b->size > i)
		{
			free(pop_stack(stack_b));
			i++;
		}
	}
}
