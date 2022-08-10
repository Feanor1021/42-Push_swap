/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_the_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:51:10 by saozcan           #+#    #+#             */
/*   Updated: 2022/08/10 14:58:05 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// pivot değerleri bulacak
int	make_pivot(t_data *s)
{
	int		i;
	long	min;
	long	max;

	i = 0;
	min = INT_MAX;
	max = INT_MIN;
	while (i++ < s->size)
	{
		if (s->array[s->size - i] > max)
			max = s->array[s->size - i];
		if (s->array[s->size - i] < min)
			min = s->array[s->size - i];
	}
	return ((max + min) / 2);
}

//bulunan pivot değeri altındakileri pushlanacak
void	send_b(t_data *a, t_data *b)
{
	int	pivot;
	int	i;
	int	total_numbers;

	i = 0;
	total_numbers = a->size;
	pivot = make_pivot(a);
	if (a->size < 3)
		return ;
	while (total_numbers > i)
	{
		if (a->array[a->size - 1] <= pivot)
		{
			push(a, b);
			}
		else
			rotate(a, 0);
		i++;
	}
	send_b(a, b);
}

//eğer b stağindeki değerin a daki yeri bulunmazsa en yüksek değer geri dönecek
int	find_max_value(t_data *a)
{
	int	i;
	int	max;
	int	index;

	i = 0;
	max = INT_MIN;
	while (i < a->size)
	{
		if (a->array[i] > max)
		{
			max = a->array[i];
			index = i;
		}
		i++;
	}
	return (index);
}

//b stağindeki değerin a daki en uygun index numarası
int	find_index(t_data *a, int numb)
{
	int	i;
	int	min;
	int	diff;
	int	index;

	i = 0;
	min = INT_MAX;
	index = -1;
	while (i < a->size)
	{
		diff = a->array[a->size - 1 - i] - numb;
		if (diff < min && diff > 0)
		{
			min = diff;
			index = i;
		}
		i++;
	}
	if (index == -1)
		index = find_max_value(a);
	return (index);
}

/*en kısa yolu bulan fonksiyon, b deki her değer için a daki
* yollar hesaplanır takibinde en kısası işlem görür*/
void	find_sort_path(t_data *a, t_data *b, int *i_a, int *i_b)
{
	int	tmp[2];
	int	m;
	int	n;
	int	min;

	min = INT_MAX;
	m = -1;
	while (++m < b->size)
	{
		n = find_index(a, b->array[b->size - m - 1]);
		if (m < b->size / 2)
			tmp[0] = m;
		else
			tmp[0] = b->size - m - 1;
		if (n < a->size / 2)
			tmp[1] = n;
		else
			tmp[1] = a->size - n - 1;
		if (tmp[0] + tmp[1] < min)
		{
			min = tmp[0] + tmp[1];
			*i_b = m;
			*i_a = n;
		}
	}
}
