/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:54:25 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/25 13:39:39 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(int *stack, int stack_size)
{
	int		last;

	if (!stack)
		return ;
	if (stack_size < 2)
		return ;
	last = stack[0];
	ft_memmove(stack, stack + 1, sizeof(int) * (stack_size - 1));
	stack[stack_size - 1] = last;
}

void	ra(t_stacks *s, int is_printable)
{
	rotate(s->a, s->size_a);
	if (is_printable)
		write(1, RA, 3);
}

void	rb(t_stacks *s, int is_printable)
{
	rotate(s->b, s->size_b);
	if (is_printable)
		write(1, RB, 3);
}

void	rr(t_stacks *s, int is_printable)
{
	rotate(s->a, s->size_a);
	rotate(s->b, s->size_b);
	if (is_printable)
		write(1, RR, 3);
}
