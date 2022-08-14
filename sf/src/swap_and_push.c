/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:00:50 by fyardimc          #+#    #+#             */
/*   Updated: 2022/08/14 16:00:53 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stack *stack_a, t_stack *stack_b, int flag)
{
	if (stack_a->size == 0)
		return ;
	if (flag == 1)
		ft_printf("pb\n");
	stack_a->size--;
	stack_b->size++;
	if (!add_node_to_stack(stack_b, pop_stack(stack_a)))
		return ;
}

void	push_a(t_stack *stack_a, t_stack *stack_b, int flag)
{
	if (stack_b->size == 0)
		return ;
	if (flag == 1)
		ft_printf("pa\n");
	stack_a->size++;
	stack_b->size--;
	if (!add_node_to_stack(stack_a, pop_stack(stack_b)))
		return ;
}

void	swap_s(t_stack *stacks, char id, int flag)
{
	int	num;
	int	index;

	if (stacks->tail == NULL || stacks->size == 1)
		return ;
	if (flag == 1)
	{
		if (id == 'a')
			ft_printf("sa\n");
		else
			ft_printf("sb\n");
	}
	num = (stacks->tail)->num;
	index = (stacks->tail)->index;
	(stacks->tail)->num = (stacks->tail)->prev->num;
	(stacks->tail)->index = (stacks->tail)->prev->index;
	(stacks->tail)->prev->num = num;
	(stacks->tail)->prev->index = index;
}

void	swap_both(t_stack *stack_a, t_stack *stack_b, int flag)
{
	int	num;
	int	index;

	if ((stack_a->tail) == NULL || (stack_b->tail) == NULL || stack_a->size == 1
		|| stack_b->size == 1)
		return ;
	if (flag == 1)
		ft_printf("ss\n");
	num = (stack_a->tail)->num;
	index = (stack_a->tail)->index;
	(stack_a->tail)->num = (stack_a->tail)->prev->num;
	(stack_a->tail)->index = (stack_a->tail)->prev->index;
	(stack_a->tail)->prev->num = num;
	(stack_a->tail)->prev->index = index;
	num = (stack_b->tail)->num;
	index = (stack_b->tail)->index;
	(stack_b->tail)->num = (stack_b->tail)->prev->num;
	(stack_b->tail)->index = (stack_b->tail)->prev->index;
	(stack_b->tail)->prev->num = num;
	(stack_b->tail)->prev->index = index;
}
