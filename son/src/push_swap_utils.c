#include "push_swap.h"

void print_list(t_list *root, t_list *tail)
{
    while(tail!=root)
    {
        ft_printf("%d\n",(tail)->num);
        tail = (tail)->prev;
    }
    if(root!=NULL)
        ft_printf("%d\n",tail->num);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_size;

	i = 0;
	src_size = ft_strlen(src);
	if (dstsize)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_size);
}
