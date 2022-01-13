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

#include "../push_swap.h"

void	pa(t_stacks *s, int is_printable)
{
	if (s->size_b > 0)
	{
		ft_memmove(s->a + 1, s->a, sizeof(int) * s->size_a);
		s->a[0] = s->b[0];
		s->size_a++;
		s->size_b--;
		ft_memmove(s->b, s->b + 1, sizeof(int) * s->size_b);
		s->b[s->size_b] = 0;
		if (is_printable)
			write(1, PA, 3);
	}
}

void	pb(t_stacks *s, int is_printable)
{
	if (s->size_a > 0)
	{
		ft_memmove(s->b + 1, s->b, sizeof(int) * s->size_b);
		s->b[0] = s->a[0];
		s->size_a--;
		s->size_b++;
		ft_memmove(s->a, s->a + 1, sizeof(int) * s->size_a);
		s->a[s->size_a] = 0;
		if (is_printable)
			write(1, PB, 3);
	}
}
