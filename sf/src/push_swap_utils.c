/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:44:32 by fyardimc          #+#    #+#             */
/*   Updated: 2022/08/14 15:44:33 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_stack stack)
{
	if (stack.root == NULL || stack.tail == NULL)
		return ;
	while (stack.tail != stack.root)
	{
		ft_printf("%d %d\n", (stack.tail)->index, (stack.tail)->num);
		stack.tail = (stack.tail)->prev;
	}
	if (stack.root != NULL)
		ft_printf("%d %d\n", stack.tail->index, (stack.tail)->num);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_size;

	i = 0;
	src_size = ft_strlen(src);
	if (dstsize)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_size);
}

int	list_size(t_stack stacks)
{
	int	size;

	size = 0;
	while (stacks.tail != stacks.root)
	{
		stacks.tail = (stacks.tail)->prev;
		size++;
	}
	return (size + 1);
}

void	stacks_init(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->size = 0;
	stack_b->size = 0;
	stack_a->root = NULL;
	stack_a->tail = stack_a->root;
	stack_b->root = NULL;
	stack_b->tail = stack_b->root;
}

int	is_sorted(t_stack stack_a)
{
	int	flag;
	int	min;
	int	i;

	flag = 0;
	i = 1;
	min = (stack_a.tail)->num;
	while (stack_a.size > i)
	{
		if ((stack_a.tail)->num > (stack_a.tail)->prev->num)
		{
			flag = 1;
			break ;
		}
		i++;
		(stack_a.tail) = (stack_a.tail)->prev;
	}
	if (flag == 1)
		return (0);
	return (1);
}
