/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:31:09 by gmerlene          #+#    #+#             */
/*   Updated: 2021/12/02 16:35:13 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	process_all_instructions(t_stacks *s)
{
	char	*instruction;

	while (1)
	{
		instruction = get_next_line(0);
		if (instruction == NULL)
			return (1);
		if (process_instruction(s, instruction) == 0)
		{
			ft_puterror();
			return (0);
		}
	}
}

int	main(int argc, char **argv)
{
	t_stacks	s;

	if (argc == 1)
		return (0);
	s.a = NULL;
	initialize_stacks_structure(&s, argc, argv);
	if (s.a == NULL)
		return (1);
	if (process_all_instructions(&s) != 0)
	{
		if (check_array_sorted(s.a, s.size_a) && s.size_b == 0)
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
	}
	free_structure(&s);
	return (0);
}
