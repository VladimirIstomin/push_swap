/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:47:40 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/22 20:48:38 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(int *stack, int stack_max_size)
{
	size_t	stack_size;
	int		first;

	if (!stack)
		return ;
	stack_size = get_stack_size(stack, stack_max_size);
	if (stack_size < 2)
		return ;
	first = stack[stack_size - 1];
	ft_memmove(stack + 1, stack, sizeof(int) * (stack_size - 1));
	stack[0] = first;
}

void	ra(t_stacks *stacks)
{
	rotate(stacks->a, stacks->max_size);
}

void	rb(t_stacks *stacks)
{
	rotate(stacks->b, stacks->max_size);
}

void	rr(t_stacks *stacks)
{
	ra(stacks);
	rb(stacks);
}