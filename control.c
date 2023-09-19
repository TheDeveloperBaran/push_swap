/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakilic <bakilic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:16:06 by bakilic           #+#    #+#             */
/*   Updated: 2023/07/06 20:24:44 by bakilic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_message(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	some_checks(t_list *data, char **av)
{
	int	i;
	int	j;

	data->checks = av;
	i = 1;
	while (data->checks[i])
	{
		j = 0;
		while (data->checks[i][j])
		{
			if (data->checks[i][j] == '-' || data->checks[i][j] == '+')
			{
				j++;
				if ((data->checks[i][j] > '9' || data->checks[i][j] < '0')
					&& data->checks[i][j] != 32)
					error_message();
			}
			if ((data->checks[i][j] > '9' || data->checks[i][j] < '0')
				&& data->checks[i][j] != 32)
				error_message();
			j++;
		}
		i++;
	}
	return (0);
}

int	have_same_number(t_list *data)
{
	int	a;
	int	b;

	a = 0;
	while (a < data->size_a)
	{
		b = a + 1;
		while (b < data->size_a)
		{
			if (data->stack_a[a] == data->stack_a[b])
			{
				write(2, "Error\n", 6);
				exit(0);
			}
			else
				b++;
		}
		a++;
	}
	return (1);
}

int	sort_is_line(t_list *data)
{
	int	i;

	i = 0;
	while (i < data->size_a - 1)
	{
		if (data->stack_a[i] < data->stack_a[i + 1])
			i++;
		else
			return (0);
	}
	exit(0);
}
