/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_reverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakilic <bakilic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:16:06 by bakilic           #+#    #+#             */
/*   Updated: 2023/07/06 20:25:11 by bakilic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_rra(t_list *data)
{
	int	tmp;
	int	temp;
	int	i;

	if (data->size_a > 1)
	{
		temp = data->stack_a[data->size_a - 1];
		i = data->size_a - 1;
		while (i > 0)
		{
			tmp = data->stack_a[i];
			data->stack_a[i] = data->stack_a[i - 1];
			data->stack_a[i - 1] = tmp;
			i--;
		}
		data->stack_a[0] = temp;
		write(1, "rra\n", 4);
	}
}

void	swap_rrb(t_list *data)
{
	int	tmp;
	int	temp;
	int	i;

	if (data->size_a > 1)
	{
		temp = data->stack_b[data->size_b - 1];
		i = data->size_a - 1;
		while (i > 0)
		{
			tmp = data->stack_a[i];
			data->stack_b[i] = data->stack_b[i - 1];
			data->stack_b[i - 1] = tmp;
			i--;
		}
		data->stack_b[0] = temp;
		write(1, "rrb\n", 4);
	}
}

void	swap_rrr(t_list *data)
{
	if (data->size_a > 1)
	{
		swap_rra(data);
		swap_rrb(data);
		write(1, "rrr\n", 4);
	}
}
