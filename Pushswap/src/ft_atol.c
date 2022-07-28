/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:17:08 by fyardimc          #+#    #+#             */
/*   Updated: 2022/07/28 16:59:18 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list*   max_min_cntrl(long res, int sign)
{
    res = res * sign;
    if (res >= LONG_MIN && res <= LONG_MAX)
        return (create_stack_node(res));
    return (NULL);
}

static int ft_isdigit_all(const char *str)
{
    int flag;

    flag = 0;
    while(*str)
    {
    if (!(*str >= 48 && *str <=57))
    {
        flag = 1;
        break;
    }
    flag = 0;
    str++;
    }
    if(flag == 1)
        return 0;
    else
        return 1;
}

t_list*   ft_atol(const char *str)
{
    long    num;
    int        sign;
	t_list *node;

	if (!ft_isdigit_all(str))
		return NULL;
    num = 0;
    sign = 1;
    while ((*str >= 9 && *str <= 13) || *str == ' ')
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign *= -1;
        str++;
    }
    while ((*str <= '9' && *str >= '0'))
    {
        num = (num * 10) + (*str - 48);
        str++;
    }
    node = max_min_cntrl(num, sign);
    return (node);
}