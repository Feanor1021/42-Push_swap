

#include "push_swap.h"

int	*sort_before_indexing(t_data *a)
{
	int	i;
	int	j;
	int	*tmp;
	int	tmp_alone;

	i = -1;
	tmp = malloc(sizeof(int) * a->size);
	while (++i < a->size)
		tmp[i] = a->array[i];
	i = -1;
	while (++i < a->size)
	{
		j = i - 1;
		while (++j < a->size)
		{
			if (tmp[i] > tmp[j])
			{
				tmp_alone = tmp[i];
				tmp[i] = tmp[j];
				tmp[j] = tmp_alone;
			}
		}
	}
	return (tmp);
}

void	indexing(t_data *a)
{
	int	*sorted;
	int	i;
	int	j;

	i = 0;
	sorted = sort_before_indexing(a);
	while (i < a->size)
	{
		j = 0;
		while (j < a->size)
		{
			if (a->array[i] == sorted[j])
			{
				a->array[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free (sorted);
}
