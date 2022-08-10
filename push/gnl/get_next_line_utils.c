/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:20:32 by saozcan           #+#    #+#             */
/*   Updated: 2022/02/02 13:32:15 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	return (0);
}

void	ft_memcpy(char *str, int i)
{
	size_t	j;

	j = 0;
	while (str[i + j])
	{
		str[j] = str[i + j];
		j++;
	}
	str[j] = 0;
}

size_t	ft_strlen_new(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (++i);
		i++;
	}
	return (i);
}

char	*ft_strdup(char *s, int start, size_t len)
{
	size_t	i;
	char	*buff;

	if (!*s || len < 1)
		return (0);
	i = ft_strlen_new(s, 0);
	if (i < len)
		len = i;
	buff = malloc(len + 1);
	if (!buff)
		return (0);
	i = 0;
	s += start;
	while (i < len && s[i])
	{
		buff[i] = s[i];
		i++;
	}
	buff[i] = 0;
	return (buff);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*buff;
	char	*pos;

	buff = malloc(ft_strlen_new(s1, 0) + ft_strlen_new(s2, 0) + 1);
	if (!buff)
		return (0);
	pos = buff;
	while (*s1)
		*buff++ = *s1++;
	while (*s2)
		*buff++ = *s2++;
	*buff = 0;
	return (pos);
}
