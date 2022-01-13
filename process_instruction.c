/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: full_sort <gmerlene@student.21-school.ru   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:31:09 by gmerlene          #+#    #+#             */
/*   Updated: 2021/12/02 16:35:13 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	process_instruction(t_stacks *s, char *inst)
{
	if (ft_strlen(inst) == 3 && ft_strncmp(inst, "sa\n", 3) == 0)
		sa(s, 0);
	else if (ft_strlen(inst) == 3 && ft_strncmp(inst, "sb\n", 3) == 0)
		sb(s, 0);
	else if (ft_strlen(inst) == 3 && ft_strncmp(inst, "ss\n", 3) == 0)
		ss(s, 0);
	else if (ft_strlen(inst) == 3 && ft_strncmp(inst, "pa\n", 3) == 0)
		pa(s, 0);
	else if (ft_strlen(inst) == 3 && ft_strncmp(inst, "pb\n", 3) == 0)
		pb(s, 0);
	else if (ft_strlen(inst) == 3 && ft_strncmp(inst, "ra\n", 3) == 0)
		ra(s, 0);
	else if (ft_strlen(inst) == 3 && ft_strncmp(inst, "rb\n", 3) == 0)
		rb(s, 0);
	else if (ft_strlen(inst) == 3 && ft_strncmp(inst, "rr\n", 3) == 0)
		rr(s, 0);
	else if (ft_strlen(inst) == 4 && ft_strncmp(inst, "rra\n", 4) == 0)
		rra(s, 0);
	else if (ft_strlen(inst) == 4 && ft_strncmp(inst, "rrb\n", 4) == 0)
		rrb(s, 0);
	else if (ft_strlen(inst) == 4 && ft_strncmp(inst, "rrr\n", 4) == 0)
		rrr(s, 0);
	else
		return (0);
	return (1);
}
