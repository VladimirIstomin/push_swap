/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:36:21 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/25 13:38:47 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(int *dst, int *src, int stack_max_size)
{
	size_t	src_size;

	if (!dst || !src || !src[0])
		return ;
	src_size = get_stack_size(src, stack_max_size);
	dst[get_stack_size(dst, stack_max_size)] = src[src_size - 1];
	src[src_size - 1] = 0;
}

void	pa(t_stacks *stacks)
{
	push(stacks->a, stacks->b, stacks->max_size);
	write(1, PA, 3);
}

void	pb(t_stacks *stacks)
{
	push(stacks->b, stacks->a, stacks->max_size);
	write(1, PB, 3);
}
