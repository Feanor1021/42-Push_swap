/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <saozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:13:02 by saozcan           #+#    #+#             */
/*   Updated: 2022/03/22 03:42:16 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_together(t_data *a, t_data *b, int control)
{
	if (control == 0)
	{
		rev_rotate(a, 1);
		rev_rotate(b, 1);
		ft_printf("rrr\n");
	}
}

void	rev_rotate(t_data *data, int control)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = data->array[0];
	while (i < data->size)
	{
		data->array[i] = data->array[i + 1];
		i++;
	}
	data->array[data->size - 1] = tmp;
	if (control == 0)
	{
		if (data->type == 'a')
			ft_printf("rra\n");
		else if (data->type == 'b')
			ft_printf("rrb\n");
	}
}
