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

#include "../push_swap.h"

static void	swap(int *stack, int stack_size)
{
	int		tmp;

	if (!stack)
		return ;
	if (stack_size < 2)
		return ;
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
}

void	sa(t_stacks *s, int is_printable)
{
	swap(s->a, s->size_a);
	if (is_printable)
		write(1, SA, 3);
}

void	sb(t_stacks *s, int is_printable)
{
	swap(s->b, s->size_b);
	if (is_printable)
		write(1, SB, 3);
}

void	ss(t_stacks *s, int is_printable)
{
	swap(s->a, s->size_a);
	swap(s->b, s->size_b);
	if (is_printable)
		write(1, SS, 3);
}
