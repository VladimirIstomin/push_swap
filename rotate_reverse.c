/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:54:25 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/22 20:49:05 by gmerlene         ###   ########.fr       */
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
}

void	rrb(t_stacks *stacks)
{
	rotate_reverse(stacks->b, stacks->max_size);
}

void	rrr(t_stacks *stacks)
{
	rra(stacks);
	rrb(stacks);
}
