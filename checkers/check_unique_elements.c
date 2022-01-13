/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_unique_elements.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:41:30 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/25 14:49:16 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_unique_elements(int *array, int array_size)
{
	int	*copy_of_array;
	int	i;

	copy_of_array = malloc(sizeof(int) * array_size);
	if (!copy_of_array)
		return (0);
	copy_of_array = ft_memcpy(copy_of_array, array, sizeof(int) * array_size);
	quicksort(copy_of_array, array_size);
	i = 0;
	while (i < array_size - 1)
	{
		if (copy_of_array[i] == copy_of_array[i + 1])
		{
			ft_puterror();
			free(copy_of_array);
			return (0);
		}
		i++;
	}
	free(copy_of_array);
	return (1);
}
