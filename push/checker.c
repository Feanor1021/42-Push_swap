/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <saozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 02:23:27 by saozcan           #+#    #+#             */
/*   Updated: 2022/03/22 03:42:02 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_pros(t_data *a, t_data *b, char *s)
{
	ft_printf(s);
	if (s[0] == 's' && s[1] == 'a')
		swap(a, 1);
	else if (s[0] == 's' && s[1] == 'b')
		swap(b, 1);
	else if (s[0] == 's' && s[1] == 's')
		swap_together(a, b, 1);
	else if (s[0] == 'r' && s[1] == 'a')
		rotate(a, 1);
	else if (s[0] == 'r' && s[1] == 'b')
		rotate(b, 1);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'r')
		rev_rotate_together(a, b, 1);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'a')
		rev_rotate(a, 1);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'b')
		rev_rotate(b, 1);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'r')
		rev_rotate_together(a, b, 1);
	else if (s[0] == 'r' && s[1] == 'r')
		rotate_together(a, b, 1);
	else if (s[0] == 'p' && s[1] == 'a')
		push(b, a);
	else if (s[0] == 'p' && s[1] == 'b')
		push(a, b);
}

void	read_lines(t_data *a, t_data *b)
{
	int		total_line;
	char	*tmp;

	total_line = 0;
	while (1)
	{
		tmp = get_next_line(0);
		if (!tmp)
			break ;
		make_pros(a, b, tmp);
	}
}

int	main(int ac, char **av)
{
	t_data	a;
	t_data	b;
	int		control;

	control = -1;
	a.type = 'a';
	b.type = 'b';
	if (ac == 2)
		for_two_args(av[1], &a, &b);
	else if (ac > 2 && ac <= 502)
		for_more_args(ac, av, &a, &b);
	else
		return (0);
	read_lines(&a, &b);
	check_listed_for_checker(&a, &b, &control);
	if (control == 1 && b.size == 0)
		ft_printf("OK");
	else if (control == 0 || b.size != 0)
		ft_printf("KO");
}
