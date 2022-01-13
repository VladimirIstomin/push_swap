/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:31:09 by gmerlene          #+#    #+#             */
/*   Updated: 2021/12/02 16:35:13 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	s;

	if (argc == 1)
	{
		ft_puterror(ERROR_NO_ARGS);
		return (1);
	}
	s.a = NULL;
	initialize_stacks_structure(&s, argc, argv);
	if (s.a == NULL)
		return (1);
	if (check_array_sorted(s.a, s.size_a))
	{
		free_structure(&s);
		return (0);
	}
	else if (s.size_a <= 6)
		mini_sort(&s);
	else
		full_sort(&s);
	free_structure(&s);
	return (0);
}
