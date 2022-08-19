/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing_and_pivot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:35:04 by fyardimc          #+#    #+#             */
/*   Updated: 2022/08/17 10:35:38 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack stacks)
{
	while (stacks.tail != stacks.root)
	{
		(stacks.tail)->index = -1;
		stacks.tail = (stacks.tail)->prev;
	}
	(stacks.root)->index = -1;
}

void	index_list(t_stack *stacks)
{
	t_list	*temp;
	int		i;
	int		k;

	if (stacks->root == NULL)
		return ;
	set_index(*stacks);
	k = list_size(*stacks);
	i = 0;
	temp = find_smallest(*stacks);
	temp->index = i;
	while (k != 0)
	{
		temp = closest_list_num(*stacks, temp->num);
		if (temp != NULL)
			temp->index = i + 1;
		i++;
		k--;
	}
}

t_list	*closest_list_num(t_stack stacks, long pivot)
{
	long	fark;
	t_list	*temp;

	fark = LONG_MAX;
	temp = NULL;
	while ((stacks.tail != stacks.root) && (stacks.root != NULL))
	{
		if ((fark > (absolute_val(pivot - (stacks.tail)->num)))
			&& ((stacks.tail)->index == -1))
		{
			fark = pivot - (stacks.tail)->num;
			temp = (stacks.tail);
		}
		fark = absolute_val(fark);
		(stacks.tail) = (stacks.tail)->prev;
	}
	if ((fark > (absolute_val(pivot - (stacks.tail)->num)))
		&& ((stacks.tail)->index == -1))
	{
		fark = pivot - (stacks.tail)->num;
		temp = (stacks.tail);
	}
	fark = absolute_val(fark);
	return (temp);
}

int	pivot_finder(t_stack stacks)
{
	int	min;
	int	ret;
	int	max;
	int	a;

	a = stacks.size;
	min = INT_MAX;
	max = INT_MIN;
	while (a)
	{
		if (min > (stacks.tail)->index)
			min = (stacks.tail)->index;
		if (max < (stacks.tail)->index)
			max = (stacks.tail)->index;
		a--;
		(stacks.tail) = (stacks.tail)->prev;
	}
	ret = (max + min) / 2;
	return (ret);
}
