/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:32:33 by fyardimc          #+#    #+#             */
/*   Updated: 2022/08/17 14:07:55 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	make_pros(t_stack *stack_a, t_stack *stack_b, char *s)
{
	if (s[0] == 's' && s[1] == 'a' && s[2] == '\n')
		swap_s(stack_a, 'a', 0);
	else if (s[0] == 's' && s[1] == 'b' && s[2] == '\n')
		swap_s(stack_b, 'b', 0);
	else if (s[0] == 's' && s[1] == 's' && s[2] == '\n')
		swap_both(stack_a, stack_b, 0);
	else if (s[0] == 'r' && s[1] == 'a' && s[2] == '\n')
		shift_up_r(stack_a, 'a', 0);
	else if (s[0] == 'r' && s[1] == 'b' && s[2] == '\n')
		shift_up_r(stack_b, 'b', 0);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'r' && s[3] == '\n')
		shift_down_both(stack_a, stack_b, 0);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'a' && s[3] == '\n')
		shift_down_rr(stack_a, 'a', 0);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'b' && s[3] == '\n')
		shift_down_rr(stack_b, 'b', 0);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == '\n')
		shift_up_both(stack_a, stack_b, 0);
	else if (s[0] == 'p' && s[1] == 'a' && s[2] == '\n')
		push_a(stack_a, stack_b, 0);
	else if (s[0] == 'p' && s[1] == 'b' && s[2] == '\n')
		push_b(stack_a, stack_b, 0);
	else
		return (0);
	return (1);
}

void	read_lines(t_stack *s_a, t_stack *s_b, char **argv)
{
	char	*tmp;

	while (1)
	{
		tmp = get_next_line(0);
		if (!tmp)
			break ;
		if (!make_pros(s_a, s_b, tmp))
			ft_error(2, s_a, s_b, argv);
		free(tmp);
	}
}

int	main(int argc, char **argv)
{
	t_stack	stacks[2];

	stacks_init(&stacks[0], &stacks[1]);
	if (argc == 1)
		exit(1);
	if (!stack_create_and_control(&stacks[0], argv, argc - 1, 2))
		ft_error(2, &stacks[0], &stacks[1], argv);
	read_lines(&stacks[0], &stacks[1], argv);
	if (is_sorted(stacks[0]) && stacks[1].size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_all(&stacks[0], &stacks[1]);
	return (0);
}
