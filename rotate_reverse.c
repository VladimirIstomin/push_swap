/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:54:25 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/25 13:39:39 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_reverse(int *stack, int stack_max_size)
{
	size_t	stack_size;
	int		last;

	if (!stack)
		return ;
	stack_size = get_stack_size(stack, stack_max_size);
	if (stack_size < 2)
		return ;
	last = stack[0];
	ft_memmove(stack, stack + 1, sizeof(int) * (stack_size - 1));
	stack[stack_size - 1] = last;
}

void	rra(t_stacks *stacks)
{
	rotate_reverse(stacks->a, stacks->max_size);
	write(1, RRA, 4);
}

void	rrb(t_stacks *stacks)
{
	rotate_reverse(stacks->b, stacks->max_size);
	write(1, RRB, 4);
}

void	rrr(t_stacks *stacks)
{
	rotate_reverse(stacks->a, stacks->max_size);
	rotate_reverse(stacks->b, stacks->max_size);
	write(1, RRR, 4);
}
