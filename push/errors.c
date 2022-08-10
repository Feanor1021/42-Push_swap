
#include "push_swap.h"

void	error_mes(t_data *a, t_data *b)
{
	ft_printf("Error\n");
	free(a->array);
	free(b->array);
	exit(1);
}
