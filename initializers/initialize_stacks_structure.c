/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_s_structure.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:12:00 by gmerlene          #+#    #+#             */
/*   Updated: 2021/12/02 16:35:03 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	char	**process_argv(int argc, char **argv)
{
	if (argc == 2)
		argv = ft_split(*argv, ' ');
	return (argv);
}

static	void	free_argv(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
		return ;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
}

void	initialize_stacks_structure(t_stacks *s, int argc, char **argv)
{
	int	size;

	argv++;
	argv = process_argv(argc, argv);
	if (argv == NULL)
		return ;
	size = 0;
	while (argv[size])
		size++;
	s->size_a = size;
	s->size_b = 0;
	s->a = initialize_array_of_integers(argv, size);
	free_argv(argc, argv);
	if (!s->a)
		return ;
	s->b = ft_calloc(size, sizeof(int));
	s->solution = malloc(sizeof(int) * size);
	if (!s->b || !s->solution)
	{
		free_structure(s);
		ft_puterror(ERROR_STACK_ALLOCATION);
	}
	else
		quicksort(ft_memcpy(s->solution, s->a, size * sizeof(int)), size);
}
