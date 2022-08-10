/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <saozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 20:25:02 by fkaratay          #+#    #+#             */
/*   Updated: 2022/03/22 03:41:52 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//çift sayı kontrolü
void	check_double(t_data *a, t_data *b)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->size)
	{
		j = i;
		while (j < a->size - 1)
		{
			if (a->array[i] == a->array[j++ + 1])
				error_mes(a, b);
		}
		i++;
	}
}

// sıralımı değilmi kontrolü
void	check_listed(t_data *a, t_data *b)
{
	int	i;
	int	counter;

	i = 0;
	counter = 1;
	while (i < a->size - 1)
	{
		if (a->array[i] < a->array[i + 1])
			counter = 0;
		i++;
	}
	if (counter == 1)
	{
		free(a->array);
		free(b->array);
		exit(1);
	}
}

void	check_listed_for_checker(t_data *a, t_data *b, int *control)
{
	int	i;

	i = 0;
	(void)b;
	while (i < a->size - 1)
	{
		if (a->array[i] < a->array[i + 1])
			*control = 0;
		i++;
	}
	if (*control != 0)
		*control = 1;
}
