/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakilic <bakilic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:16:06 by bakilic           #+#    #+#             */
/*   Updated: 2023/07/06 20:24:47 by bakilic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_integer_overflow(long long num, int sign)
{
	if (((num * sign) > 2147483647) || ((num * sign) < -2147483648))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (0);
}

long	ft_atoi(const char *str)
{
	int			i;
	long int	num;
	int			sign;

	i = 0;
	num = 0;
	sign = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + str[i] - '0';
		is_integer_overflow(num, sign);
		i++;
	}
	return (num * sign);
}
