/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkaratay <fkaratay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 20:24:55 by fkaratay          #+#    #+#             */
/*   Updated: 2022/03/21 20:24:57 by fkaratay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BASE
#  define BASE "0123456789abcdef"
# endif

# ifndef BASEV2
#  define BASEV2 "0123456789ABCDEF"
# endif

void	ft_putchar(char c, int *count);
void	ft_putstr(const char *str, int *count);
void	ft_putnbr(long double nbr, int base, int *count);
void	ft_section_part(va_list lst, const char str, int *count);
int		ft_printf(const char *str, ...);

#endif
