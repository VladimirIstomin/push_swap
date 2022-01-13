/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_rotations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: full_sort <gmerlene@student.21-school.ru   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:31:09 by gmerlene          #+#    #+#             */
/*   Updated: 2021/12/02 16:35:13 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	int	calculate_rotations_in_b(t_stacks *s, int pos_in_b)
{
	if (pos_in_b < s->size_b - pos_in_b)
		return (pos_in_b);
	else
		return (-(s->size_b - pos_in_b));
}

static	int	calculate_rotations_in_a_usual(t_stacks *s, int pos_in_b)
{
	int	i;
	int	element;

	i = 0;
	element = s->b[pos_in_b];
	while (i < s->size_a - 1)
	{
		if (s->a[i] < element && s->a[i + 1] > element)
		{
			if (i + 1 < s->size_a - i - 1)
				return (i + 1);
			else
				return (-(s->size_a - i - 1));
		}
		i++;
	}
	return (s->size_a);
}

static	int	calculate_rotations_in_a_edges(t_stacks *s, int pos_in_b)
{
	int	element;

	element = s->b[pos_in_b];
	if (s->a[0] > element && s->a[s->size_a - 1] < element)
		return (0);
	return (s->size_a);
}

static	int	calculate_rotations_in_a_minmax(t_stacks *s, int pos_in_b)
{
	int	min_index_in_a;
	int	max_index_in_a;
	int	element;

	element = s->b[pos_in_b];
	min_index_in_a = find_min_index_in_array(s->a, s->size_a);
	max_index_in_a = find_max_index_in_array(s->a, s->size_a);
	if (element < s->a[min_index_in_a]
		|| element > s->a[max_index_in_a])
	{
		if (max_index_in_a + 1 < s->size_a - min_index_in_a)
			return (max_index_in_a + 1);
		else
			return (-(s->size_a - min_index_in_a));
	}
	return (s->size_a);
}

void	define_rotations_for_index(t_stacks *s, t_rotations *rot, int pos_in_b)
{
	int	tmp;

	rot->a_rotations = calculate_rotations_in_a_usual(s, pos_in_b);
	tmp = calculate_rotations_in_a_edges(s, pos_in_b);
	if (ft_abs(rot->a_rotations) > ft_abs(tmp))
		rot->a_rotations = tmp;
	tmp = calculate_rotations_in_a_minmax(s, pos_in_b);
	if (ft_abs(rot->a_rotations) > ft_abs(tmp))
		rot->a_rotations = tmp;
	rot->b_rotations = calculate_rotations_in_b(s, pos_in_b);
	rot->total_rotations = ft_abs(rot->a_rotations) + ft_abs(rot->b_rotations);
}
