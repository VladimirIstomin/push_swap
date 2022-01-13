/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:47:40 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/25 13:38:17 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate_reverse(int *stack, int stack_size)
{
	int		first;

	if (!stack)
		return ;
	if (stack_size < 2)
		return ;
	first = stack[stack_size - 1];
	ft_memmove(stack + 1, stack, sizeof(int) * (stack_size - 1));
	stack[0] = first;
}

void	rra(t_stacks *s, int is_printable)
{
	rotate_reverse(s->a, s->size_a);
	if (is_printable)
		write(1, RRA, 4);
}

void	rrb(t_stacks *s, int is_printable)
{
	rotate_reverse(s->b, s->size_b);
	if (is_printable)
		write(1, RRB, 4);
}

void	rrr(t_stacks *s, int is_printable)
{
	rotate_reverse(s->a, s->size_a);
	rotate_reverse(s->b, s->size_b);
	if (is_printable)
		write(1, RRR, 4);
}
