/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:56:17 by fyardimc          #+#    #+#             */
/*   Updated: 2022/08/14 16:50:00 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../push_swap.h"
# include "../ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12323
# endif

char	*get_next_line(int fd);
char	*get_till_n(int fd, char *line);

char	*get_line(char *line);
char	*skip_next_n(char *line);

char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif