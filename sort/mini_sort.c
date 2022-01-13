/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mini_sort <gmerlene@student.21-school.ru   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:31:09 by gmerlene          #+#    #+#             */
/*   Updated: 2021/12/02 16:35:13 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	void	sort_three_a(t_stacks *s)
{
	if (check_array_sorted(s->a, s->size_a))
		return ;
	if (s->a[0] < s->a[1] && s->a[0] > s->a[2] && s->a[1] > s->a[2])
		rra(s, 1);
	else if (s->a[0] > s->a[1] && s->a[0] > s->a[2] && s->a[1] < s->a[2])
		ra(s, 1);
	else
		sa(s, 1);
	if (s->a[0] > s->a[1])
		ra(s, 1);
	else if (s->a[1] > s->a[2])
		rra(s, 1);
}

static	void	sort_three_b(t_stacks *s)
{
	if (check_array_sorted(s->b, s->size_b))
		return ;
	if (s->b[0] < s->b[1] && s->b[0] > s->b[2] && s->b[1] > s->b[2])
		rrb(s, 1);
	else if (s->b[0] > s->b[1] && s->b[0] > s->b[2] && s->b[1] < s->b[2])
		rb(s, 1);
	else
		sb(s, 1);
	if (s->b[0] > s->b[1])
		rb(s, 1);
	else if (s->b[1] > s->b[2])
		rrb(s, 1);
}

static	void	merge_stacks(t_stacks *s)
{
	int	max_in_a;
	int	min;

	max_in_a = s->a[s->size_a - 1];
	min = s->solution[0];
	while (s->size_b != 0)
	{
		if (s->a[0] > s->b[0] || (s->b[0] > max_in_a && s->a[0] == min))
			pa(s, 1);
		ra(s, 1);
	}
	while (s->a[0] != s->solution[0])
		ra(s, 1);
}

void	mini_sort(t_stacks *s)
{
	if (s->size_a == 2)
	{
		sa(s, 1);
		return ;
	}
	while (s->size_a > 3)
		pb(s, 1);
	sort_three_a(s);
	if (s->size_b == 2 && !check_array_sorted(s->b, 2))
		sb(s, 1);
	sort_three_b(s);
	merge_stacks(s);
}
