/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:48:59 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/23 14:16:08 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	swap_array_elements(int *array, int i, int j)
{
	int	tmp;

	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

static int	sort_relative_to_pivot(int *array, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	pivot = array[start];
	i = start + 1;
	j = start + 1;
	while (i <= end)
	{
		if (array[i] < pivot)
		{
			swap_array_elements(array, i, j);
			j++;
		}
		i++;
	}
	swap_array_elements(array, start, j - 1);
	return (j - 1);
}

static void	sort(int *array, int start, int end)
{
	int	pivot_index;

	if (start < end)
	{
		pivot_index = sort_relative_to_pivot(array, start, end);
		sort(array, start, pivot_index - 1);
		sort(array, pivot_index + 1, end);
	}
}

void	quicksort(int *array, int array_size)
{
	sort(array, 0, array_size - 1);
}
