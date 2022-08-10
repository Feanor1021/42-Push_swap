/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkaratay <fkaratay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 20:24:49 by fkaratay          #+#    #+#             */
/*   Updated: 2022/03/21 20:24:51 by fkaratay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *count)
{
	*count += write(1, &c, 1);
}

void	ft_putstr(const char *str, int *count)
{
	if (!str)
	{
		*count += write(1, "(null)", 6);
		return ;
	}
	while (*str)
		*count += write(1, &(*str++), 1);
}

void	ft_putnbr(long double nbr, int base, int *count)
{
	if (nbr < 0)
	{
		if (base != 16)
			ft_putchar('-', count);
		nbr *= -1;
	}
	if (base == 15)
	{
		if (nbr >= 16)
			ft_putnbr(((unsigned long)nbr / 16), 15, count);
		ft_putchar(BASEV2[(unsigned long)nbr % 16], count);
		return ;
	}
	else if (nbr >= base)
		ft_putnbr(((unsigned long)nbr / base), base, count);
	ft_putchar(BASE[(unsigned long)nbr % base], count);
}

void	ft_section_part(va_list lst, const char str, int *count)
{
	if (str == 's')
		ft_putstr(va_arg(lst, char *), count);
	else if (str == 'd' || str == 'i')
		ft_putnbr(va_arg(lst, int), 10, count);
	else if (str == 'c')
		ft_putchar(va_arg(lst, int), count);
	else if (str == 'p')
	{
		*count += write(1, "0x", 2);
		ft_putnbr(va_arg(lst, unsigned long), 16, count);
	}
	else if (str == 'x')
		ft_putnbr(va_arg(lst, unsigned int), 16, count);
	else if (str == 'u')
		ft_putnbr(va_arg(lst, unsigned int), 10, count);
	else if (str == 'X')
		ft_putnbr(va_arg(lst, unsigned int), 15, count);
	else
		ft_putchar(str, count);
}

int	ft_printf(const char *str, ...)
{
	va_list	lst;
	int		*count;
	int		lastcount;

	count = malloc(4);
	*count = 0;
	va_start(lst, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_section_part(lst, *str, count);
		}
		else
			ft_putchar(*str, count);
		str++;
	}
	va_end(lst);
	lastcount = *count;
	free(count);
	return (lastcount);
}
/*
int	main(void)
{
	//count =printf(" %p ", -1);
	ft_printf(" %d \n", -1);
	//ft_printf("%p", 'c');
}*/
