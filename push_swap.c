/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakilic <bakilic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:16:06 by bakilic           #+#    #+#             */
/*   Updated: 2023/07/07 18:10:30 by bakilic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	control_size(t_list *data, char **av)
{
	int	i;
	int	j;
	int	size;

	i = 1;
	size = 0;
	while (av[i])
	{
		j = 0;
		data->split = ft_split(av[i], ' ');
		while (data->split[j])
		{
			size++;
			j++;
		}
		free_split(data->split);
		i++;
	}
	data->size_a = size;
	data->size_b = 0;
	data->size_tmp = size;
}

void	storage_place(t_list *data, char **av)
{
	int	i;
	int	j;
	int	z;

	i = 1;
	z = 0;
	control_size(data, av);
	data->stack_a = malloc(sizeof(int) * data->size_a);
	data->tmp_a = malloc(sizeof(int) * data->size_a);
	while (av[i])
	{
		j = 0;
		data->split = ft_split(av[i], ' ');
		while (data->split[j])
		{
			data->stack_a[z++] = ft_atoi(data->split[j]);
			j++;
		}
		free_split(data->split);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_list	*data;

	if (ac >= 2)
	{
		data = malloc(sizeof(t_list));
		control_size(data, av);
		storage_place(data, av);
		have_same_number(data);
		some_checks(data, av);
		sort_is_line(data);
		data_sort(data);
		find_sort_index(data);
		if (data->size_a > 5)
			radix(data);
		else
			small_sort(data);
	}
}
