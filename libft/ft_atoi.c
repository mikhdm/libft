/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 00:45:30 by rmander           #+#    #+#             */
/*   Updated: 2020/11/12 21:48:22 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_pow(long n, long power)
{
	long	res;

	res = 1;
	while (power--)
		res *= n;
	return (res);
}

int			ft_atoi(const char *str)
{
	long		result;
	const char	*end;
	int			neg;
	int			count;
	int			i;

	neg = 0;
	result = 0;
	count = 0;
	i = 0;
	if (*str == '-')
	{
		str++;
		neg = 1;
	}
	end = str;
	while (*end && ft_isdigit(*end))
	{
		count++;
		end++;
	}
	end--;
	while (i < count)
		result += (*end-- - '0') * ft_pow(10, i++);
	return ((int)((neg) ? result * (-1) : result));
}
