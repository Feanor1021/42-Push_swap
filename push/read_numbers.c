/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <saozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 02:25:17 by saozcan           #+#    #+#             */
/*   Updated: 2022/03/22 02:26:52 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	number_counter(char *s, t_data *a, t_data *b)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] == ' ' || s[i] == '\t')
			i++;
		if ((s[i] >= '0' && s[i] <= '9') || (s[i] == '-' || s[i] == '+'))
			counter++;
		else
			error_mes(a, b);
		while ((s[i] >= '0' && s[i] <= '9') || (s[i] == '-' || s[i] == '+'))
			i++;
	}
	return (counter);
}

int	ft_atoi(char *s, t_data *a, t_data *b)
{
	int		i;
	long	res;
	int		neg;

	i = 0;
	neg = 1;
	res = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			neg *= -1;
		i++;
	}
	while (s[i])
	{
		if (!((s[i] >= '0' && s[i] <= '9') || s[i] == ' '))
			error_mes(a, b);
		if (s[i] == ' ' || s[i] == '\t')
			return (res * neg);
		res = (res * 10) + s[i++] - '0';
		if (res > INT_MAX)
			error_mes(a, b);
	}
	return (res * neg);
}

// ac == 2 durumu
void	for_two_args(char *s, t_data *a, t_data *b)
{
	int	i;
	int	total_number;
	int	number_index;

	number_index = 0;
	i = 0;
	total_number = number_counter(s, a, b);
	a->size = total_number;
	b->size = 0;
	b->array = malloc(sizeof(int) * total_number);
	a->array = malloc(sizeof(int) * total_number);
	while (s[i])
	{
		while (s[i] == ' ' || s[i] == '\t')
			i++;
		if ((s[i] >= '0' && s[i] <= '9') || (s[i] == '-' || s[i] == '+'))
			a->array[total_number - 1 - number_index++] = ft_atoi(s + i, a, b);
		while ((s[i] >= '0' && s[i] <= '9') || (s[i] == '-' || s[i] == '+'))
			i++;
	}
}

// ac nin 2 den fazla durumu
void	for_more_args(int ac, char **av, t_data *a, t_data *b)
{
	int	i;

	i = 0;
	a->array = malloc(sizeof(int) * (ac - 1));
	b->array = malloc(sizeof(int) * (ac - 1));
	a->size = ac - 1;
	b->size = 0;
	while (++i < ac)
		a->array[ac - 1 - i] = ft_atoi(av[i], a, b);
}
