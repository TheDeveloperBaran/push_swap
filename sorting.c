/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakilic <bakilic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:16:06 by bakilic           #+#    #+#             */
/*   Updated: 2023/07/07 20:07:59 by bakilic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	data_sort(t_list *data)
{
	int	i;
	int	temp;
	int	len;

	i = 0;
	len = data->size_a;
	while (i < len)
	{
		data->tmp_a[i] = data->stack_a[i];
		i++;
	}
	i = 0;
	while (i < len - 1)
	{
		if (data->tmp_a[i] > data->tmp_a[i + 1])
		{
			temp = data->tmp_a[i];
			data->tmp_a[i] = data->tmp_a[i + 1];
			data->tmp_a[i + 1] = temp;
			i = -1;
		}
		i++;
	}
	i = 0;
}
