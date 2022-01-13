/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_array_of_integers.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:38:26 by gmerlene          #+#    #+#             */
/*   Updated: 2021/12/02 16:38:15 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*initialize_array_of_integers(char **argv, int size)
{
	int	i;
	int	*array;

	i = 0;
	array = malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	while (i < size)
	{
		if (check_integer(argv[i]))
			array[i] = ft_atoi(argv[i]);
		else
		{
			free(array);
			return (NULL);
		}
		i++;
	}
	if (!check_unique_elements(array, size))
	{
		free(array);
		return (NULL);
	}
	return (array);
}
