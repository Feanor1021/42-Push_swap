/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 09:41:11 by saozcan           #+#    #+#             */
/*   Updated: 2022/02/02 13:35:00 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*send_part(char **str)
{
	char	*buff;
	size_t	i;

	i = 0;
	buff = *str;
	if (!buff[i])
		return (0);
	i = ft_strlen_new(*str, '\n');
	if (i == ft_strlen_new(*str, '\0'))
	{
		buff = ft_strdup(*str, 0, i);
		free(*str);
		*str = NULL;
		return (buff);
	}
	buff = ft_strdup(*str, 0, i);
	ft_memcpy(*str, i);
	return (buff);
}

char	*read_part(char *str, char *buff, int fd)
{
	char	*tmp;
	int		i;

	i = read(fd, buff, BUFFER_SIZE);
	buff[i] = 0;
	while (i > 0)
	{
		if (!str)
			str = ft_strdup(buff, 0, i);
		else if (str)
		{
			tmp = str;
			str = ft_strjoin(str, buff);
			free(tmp);
		}
		if (ft_strchr(str, '\n') || i != BUFFER_SIZE)
			break ;
		i = read(fd, buff, BUFFER_SIZE);
		buff[i] = 0;
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str = 0;
	char		*buff;

	buff = malloc(BUFFER_SIZE + 1);
	if (fd < 0 || !buff || read(fd, buff, 0) == -1)
	{
		free(buff);
		return (0);
	}
	str = read_part(str, buff, fd);
	if (!str)
		return (0);
	return (send_part(&str));
}

/*int	main(void)
{
	int file;
	int i = 0;
	char *a;

	file = open("test", O_RDONLY);
	while (i++ < 3){
		printf("%s\n", a = get_next_line(file));
		free(a);
	}
	system("leaks a.out");
	//char a[] = "onur\nbebegim";
	//ft_memcpy(a, 5);
	//printf("%s\n", a);
}*/
