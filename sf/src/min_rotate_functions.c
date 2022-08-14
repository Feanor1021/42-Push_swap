/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_rotate_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:43:38 by fyardimc          #+#    #+#             */
/*   Updated: 2022/08/14 15:56:13 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_rrb(t_stack stacks, int index, int size)
{
	int		rr;
	t_list	*temp;

	temp = stacks.tail;
	rr = 0;
	while ((temp->index != index) && size != 0)
	{
		temp = temp->next;
		size--;
	}
	while (temp != stacks.tail)
	{
		temp = temp->prev;
		rr++;
	}
	return (rr);
}

int	min_rot(t_stack stacks, int index, int size)
{
	int		r;
	t_list	*temp;

	temp = stacks.tail;
	r = 0;
	while ((temp->index != index) && size != 0)
	{
		temp = temp->prev;
		size--;
	}
	while (temp != stacks.tail)
	{
		temp = temp->next;
		r++;
	}
	return (r);
}

void	rr_x_times(t_stack *stack, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		shift_down_rr(stack, 'a', 1);
		i++;
	}
}

void	r_x_times(t_stack *stack, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		shift_up_r(stack, 'a', 1);
		i++;
	}
}

int	closest_index_b(t_stack stacks, int index, int size)
{
	int	fark;
	int	flag;

	fark = INT_MAX;
	flag = 0;
	while (size)
	{
		if (stacks.tail != NULL && (stacks.tail)->index > index)
		{
			flag = 1;
			if ((fark > (absolute_val(index - (stacks.tail)->index))))
			{
				fark = index - (stacks.tail)->index;
			}
			fark = absolute_val(fark);
		}
		if ((stacks.tail) != NULL)
			(stacks.tail) = (stacks.tail)->prev;
		size--;
	}
	if (flag == 1)
		return (index + fark);
	return (find_max_value(stacks));
}
