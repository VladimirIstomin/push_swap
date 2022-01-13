/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:43:01 by gmerlene          #+#    #+#             */
/*   Updated: 2021/12/02 15:04:29 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_puterror()
{
	ft_putstr_fd("Error\n", 2);
}

void	free_structure(t_stacks *s)
{
	if (s->a)
		free(s->a);
	if (s->b)
		free(s->b);
	if (s->solution)
		free(s->solution);
	s->a = NULL;
	s->b = NULL;
	s->solution = NULL;
}

int	find_max_index_in_array(int *array, int array_size)
{
	int	i;
	int	max;
	int	max_index;

	i = 1;
	max = array[0];
	max_index = 0;
	while (i < array_size)
	{
		if (array[i] > max)
		{
			max = array[i];
			max_index = i;
		}
		i++;
	}
	return (max_index);
}

int	find_min_index_in_array(int *array, int array_size)
{
	int	i;
	int	min;
	int	min_index;

	i = 1;
	min = array[0];
	min_index = 0;
	while (i < array_size)
	{
		if (array[i] < min)
		{
			min = array[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}
