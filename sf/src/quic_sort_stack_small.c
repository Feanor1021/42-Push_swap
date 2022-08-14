/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quic_sort_stack_small.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:46:57 by fyardimc          #+#    #+#             */
/*   Updated: 2022/08/14 15:56:13 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tree_arg_sort(t_stack *s_a, t_stack *s_b)
{
	index_list(s_a);
	if (is_sorted(*s_a))
		return ;
	if ((s_a->root)->index == 1 && (s_a->root)->next->index == 2
		&& ((s_a->tail)->index) == 0)
	{
		shift_down_rr(s_a, 'a', 1);
		swap_s(s_a, 'a', 1);
	}
	else if ((s_a->root)->index == 2 && (s_a->root)->next->index == 0
		&& ((s_a->tail)->index) == 1)
		swap_s(s_a, 'a', 1);
	else if ((s_a->root)->index == 0 && (s_a->root)->next->index == 2
		&& ((s_a->tail)->index) == 1)
		shift_down_rr(s_a, 'a', 1);
	else if ((s_a->root)->index == 0 && (s_a->root)->next->index == 1
		&& ((s_a->tail)->index) == 2)
	{
		swap_s(s_a, 'a', 1);
		shift_down_rr(s_a, 'a', 1);
	}
	else
		shift_up_r(s_a, 'a', 1);
}

void	quad_arg_sort(t_stack *s_a, t_stack *s_b)
{
	int	index_a;

	index_list(s_a);
	if (is_sorted(*s_a))
		return ;
	index_a = min_rot(*s_a, 0, s_a->size);
	if (index_a < (s_a->size / 2))
		while (index_a-- > 0)
			shift_up_r(s_a, 'a', 1);
	else
		while (index_a++ < s_a->size)
			shift_down_rr(s_a, 'a', 1);
	push_b(s_a, s_b, 1);
	tree_arg_sort(s_a, s_b);
	push_a(s_a, s_b, 1);
}

void	nonp_arg_sort(t_stack *s_a, t_stack *s_b)
{
	int	index_a;

	index_list(s_a);
	index_a = min_rot(*s_a, 0, s_a->size);
	if (index_a < (s_a->size / 2))
		while (index_a-- > 0)
			shift_up_r(s_a, 'a', 1);
	else
		while (index_a++ < s_a->size)
			shift_down_rr(s_a, 'a', 1);
	push_b(s_a, s_b, 1);
	quad_arg_sort(s_a, s_b);
	push_a(s_a, s_b, 1);
}
