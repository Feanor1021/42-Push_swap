/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:42:46 by fyardimc          #+#    #+#             */
/*   Updated: 2022/08/14 21:13:37 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stacks[2];

	stacks_init(&stacks[0], &stacks[1]);
	if (argc == 1)
		exit(1);
	if (!stack_create_and_control(&stacks[0], argv, argc - 1))
		ft_error();
	if (is_sorted(stacks[0]))
		exit(1);
	if (stacks[0].size > 5)
	{
		index_list(&stacks[0]);
		sort_stack(&stacks[0], &stacks[1]);
	}
	else
		sort_small_stacks(&stacks[0], &stacks[1], stacks[0].size);
	free_all(&stacks[0], &stacks[1]);
	return (0);
}
