/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:00:10 by fyardimc          #+#    #+#             */
/*   Updated: 2022/08/14 17:31:27 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_node_to_stack(t_stack *stacks, t_list *temp)
{
	if (temp == NULL)
	{
		return (0);
	}
	if ((stacks->root) == NULL)
	{
		(stacks->root) = temp;
		(stacks->root)->next = (stacks->root);
		(stacks->root)->prev = (stacks->root);
		(stacks->tail) = (stacks->root);
	}
	else
	{
		(stacks->tail)->next = temp;
		(stacks->tail)->next->prev = (stacks->tail);
		(stacks->tail) = (stacks->tail)->next;
		(stacks->tail)->next = (stacks->root);
		(stacks->root)->prev = (stacks->tail);
	}
	return (1);
}

t_list	*create_stack_node(long num)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->num = num;
	return (node);
}

t_list	*pop_stack(t_stack *stacks)
{
	t_list	*temp;

	if ((stacks->root) == NULL)
		return (NULL);
	else if ((stacks->root)->next == (stacks->root))
	{
		temp = (stacks->root);
		(stacks->root) = NULL;
		(stacks->tail) = NULL;
		return (temp);
	}
	else
	{
		temp = (stacks->tail);
		(stacks->tail) = (stacks->tail)->prev;
		(stacks->tail)->next = (stacks->root);
		(stacks->root)->prev = (stacks->tail);
		return (temp);
	}
	return (NULL);
}
