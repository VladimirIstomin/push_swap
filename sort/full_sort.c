/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene  <gmerlene@student.21-school.ru   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:31:09 by gmerlene          #+#    #+#             */
/*   Updated: 2021/12/02 16:35:13 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	void	define_next_rotations(t_stacks *s, t_rotations *rotations)
{
	int			i;
	t_rotations	local_rotations;

	define_rotations_for_index(s, rotations, 0);
	i = 1;
	while (i < s->size_b)
	{
		define_rotations_for_index(s, &local_rotations, i);
		if (local_rotations.total_rotations < rotations->total_rotations)
		{
			rotations->a_rotations = local_rotations.a_rotations;
			rotations->b_rotations = local_rotations.b_rotations;
			rotations->total_rotations = local_rotations.total_rotations;
		}
		i++;
	}
}

static	void	rotate_b_n_times(t_stacks *s, int n_times)
{
	int	i;

	i = 0;
	if (n_times > 0)
	{
		while (i++ < n_times)
			rb(s, 1);
	}
	else
	{
		n_times = -n_times;
		while (i++ < n_times)
			rrb(s, 1);
	}
}

static	void	rotate_a_n_times(t_stacks *s, int n_times)
{
	int	i;

	i = 0;
	if (n_times > 0)
	{
		while (i++ < n_times)
			ra(s, 1);
	}
	else
	{
		n_times = -n_times;
		while (i++ < n_times)
			rra(s, 1);
	}
}

static	int	calculate_rotations_in_a_till_sorted(t_stacks *s)
{
	int	i;

	i = 0;
	while (s->a[i] != s->solution[0])
		i++;
	if (i < s->size_a - i)
		return (i);
	else
		return (-(s->size_a - i));
}

void	full_sort(t_stacks *s)
{
	t_rotations	rotations;
	int			size;

	size = s->size_a;
	while (s->size_a != 2)
	{
		if (s->a[0] != s->solution[0] && s->a[0] != s->solution[size - 1])
		{
			pb(s, 1);
			if (s->b[0] > s->solution[size / 2])
				rb(s, 1);
		}
		else
			ra(s, 1);
	}
	while (s->size_b != 0)
	{
		define_next_rotations(s, &rotations);
		rotate_b_n_times(s, rotations.b_rotations);
		rotate_a_n_times(s, rotations.a_rotations);
		pa(s, 1);
	}
	rotate_a_n_times(s, calculate_rotations_in_a_till_sorted(s));
}
