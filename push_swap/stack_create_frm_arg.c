/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create_frm_arg.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:58:37 by fyardimc          #+#    #+#             */
/*   Updated: 2022/08/17 13:38:52 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dublicated_check(t_stack stack)
{
	while (stack.tail != stack.root)
	{
		if ((stack.tail)->num == (stack.root)->num)
			return (0);
		stack.root = (stack.root)->next;
	}
	return (1);
}

int	string_checker(t_stack *stack_a, char *argv)
{
	int	size_a;

	if (!argv || !*argv)
		return (0);
	size_a = add_node_to_stack(stack_a, ft_atol(argv));
	if (!size_a)
		return (0);
	if (((stack_a->root) != (stack_a->tail)) && (!dublicated_check(*stack_a)))
		return (0);
	stack_a->size += size_a;
	return (1);
}

int	ft_isspace_srch_all(char *argv_sub)
{
	int	flag;

	flag = 1;
	while (*argv_sub)
	{
		if (*argv_sub == ' ')
			flag = 0;
		argv_sub++;
	}
	if (flag == 1)
		return (1);
	return (0);
}

int	ft_size(char **argv)
{
	int	i;

	if (!argv)
		return (0);
	i = 0;
	while (argv[i])
	{
		i++;
	}
	return (i);
}

int	stack_create_and_control(t_stack *stack_a, char **argv, int argc, int flag)
{
	int		i;
	char	**argv_sub;

	argv_sub = NULL;
	while (argc >= 1)
	{
		if (ft_isspace_srch_all(argv[argc]))
		{
			if (!string_checker(stack_a, argv[argc]))
				ft_error(flag, stack_a, stack_a, argv_sub);
		}
		else
		{
			argv_sub = ft_split(argv[argc], flag, stack_a, stack_a);
			i = ft_size(argv_sub);
			while (i--)
			{
				if (!string_checker(stack_a, argv_sub[i]))
					ft_error(flag, stack_a, stack_a, argv_sub);
			}
		}
		argc--;
	}
	free_split(argv_sub);
	return (1);
}
