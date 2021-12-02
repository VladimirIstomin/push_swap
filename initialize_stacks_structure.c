/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stacks_structure.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:12:00 by gmerlene          #+#    #+#             */
/*   Updated: 2021/12/02 15:37:18 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_stacks_structure(t_stacks *stacks, char **argv)
{
	int	max_size;
	int	*empty_array;
	int	*solution_array;

	max_size = 0;
	while (argv[max_size])
		max_size++;
	stacks->a = initialize_array_of_integers(argv, max_size);
	if (!stacks->a)
		return ;
	empty_array = ft_calloc(max_size, sizeof(int));
	solution_array = malloc(sizeof(int) * max_size);
	if (!empty_array || !solution_array)
		free_structure(stacks);
	else
	{
		stacks->b = empty_array;
		stacks->solution = quicksort(
				ft_memcpy(solution_array, stacks->a, max_size * sizeof(int)));
	}
}
