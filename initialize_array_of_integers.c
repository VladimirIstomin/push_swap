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

#include "push_swap.h"

int	*initialize_array_of_integers(char **argv, int max_size)
{
	int	i;
	int	*array;

	i = 0;
	array = malloc(sizeof(int) * max_size);
	if (!array)
		return (NULL);
	while (i < max_size)
	{
		if (check_integer(argv[i + 1]))
			array[i] = ft_atoi(argv[i + 1]);
		else
		{
			free(array);
			return (NULL);
		}
		i++;
	}
	if (!check_unique_elements(array, max_size))
	{
		free(array);
		return (NULL);
	}
	return (array);
}
