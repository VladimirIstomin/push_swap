/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:23:50 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/25 13:37:45 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *stack, int stack_max_size)
{
	size_t	stack_size;
	int		tmp;

	if (!stack)
		return ;
	stack_size = get_stack_size(stack, stack_max_size);
	if (stack_size < 2)
		return ;
	tmp = stack[stack_size - 1];
	stack[stack_size - 1] = stack[stack_size - 2];
	stack[stack_size - 2] = tmp;
}

void	sa(t_stacks *stacks)
{
	swap(stacks->a, stacks->max_size);
	write(1, SA, 3);
}

void	sb(t_stacks *stacks)
{
	swap(stacks->b, stacks->max_size);
	write(1, SB, 3);
}

void	ss(t_stacks *stacks)
{
	swap(stacks->a, stacks->max_size);
	swap(stacks->b, stacks->max_size);
	write(1, SS, 3);
}
