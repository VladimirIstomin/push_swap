/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_array_sorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:36:01 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/23 14:38:23 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_array_sorted(int *array, int array_size)
{
	int	i;

	i = 0;
	while (i < array_size - 1)
	{
		if (array[i] > array[i + 1])
			return (0);
		i++;
	}
	return (1);
}
