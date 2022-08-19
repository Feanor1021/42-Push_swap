/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:45:35 by fyardimc          #+#    #+#             */
/*   Updated: 2022/08/17 13:26:27 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char const *s1, unsigned int start, size_t len)
{
	char			*arry;
	unsigned int	size_s1;

	if (!s1)
		return (NULL);
	size_s1 = ft_strlen(s1);
	if (start >= ft_strlen(s1))
	{
		arry = (char *)malloc(sizeof(char));
		if (!arry)
			return (NULL);
		*arry = '\0';
		return (arry);
	}
	arry = (char *)malloc(sizeof(char) * (len + 1));
	if (!arry)
		return (arry);
	ft_strlcpy(arry, (char *)(s1 + start), len + 1);
	return (arry);
}

static void	ft_allocate(char **tab, char const *s, char sep)
{
	char		**tab_p;
	char const	*tmp;

	tmp = s;
	tab_p = tab;
	while (*tmp)
	{
		while (*s == sep)
			++s;
		tmp = s;
		while (*tmp && *tmp != sep)
			++tmp;
		if (tmp > s)
		{
			*tab_p = ft_substr(s, 0, tmp - s);
			s = tmp;
			++tab_p;
		}
	}
	*tab_p = NULL;
}

static int	ft_count_words(char const *s, char sep)
{
	int	word_count;

	word_count = 0;
	while (*s)
	{
		while (*s == sep)
			++s;
		if (*s)
			++word_count;
		while (*s && *s != sep)
			++s;
	}
	return (word_count);
}

char	**ft_split(char const *s, int flag, t_stack *stack_a, t_stack *stack_b)
{
	char	**new;
	int		size;

	new = NULL;
	if (!s)
		return (NULL);
	while (*s == ' ' || (*s <= 13 && *s >= 9))
		s++;
	if (*s == '\0')
		ft_error(flag, stack_a, stack_b, new);
	size = ft_count_words(s, ' ');
	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (NULL);
	ft_allocate(new, s, ' ');
	return (new);
}

void	free_split(char **argv)
{
	int	i;

	if (argv == NULL)
		return ;
	if (argv[0][0] == '.' && argv[0][1] == '/')
		return ;
	i = ft_size(argv);
	while (i >= 0)
	{
		free(argv[i]);
		i--;
	}
	free(argv);
}
