/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:27:38 by gmerlene          #+#    #+#             */
/*   Updated: 2021/12/02 16:36:55 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

typedef struct s_stacks
{
	int	*a;
	int	*b;
	int	*solution;
	int	size_a;
	int	size_b;
}		t_stacks;

typedef struct s_rotations
{
	int	a_rotations;
	int	b_rotations;
	int	total_rotations;
}		t_rotations;

# define SA "sa\n"
# define SB "sb\n"
# define SS "ss\n"
# define PA "pa\n"
# define PB "pb\n"
# define RA "ra\n"
# define RB "rb\n"
# define RR "rr\n"
# define RRA "rra\n"
# define RRB "rrb\n"
# define RRR "rrr\n"

void	sa(t_stacks *s, int is_printable);
void	sb(t_stacks *s, int is_printable);
void	ss(t_stacks *s, int is_printable);
void	pa(t_stacks *s, int is_printable);
void	pb(t_stacks *s, int is_printable);
void	ra(t_stacks *s, int is_printable);
void	rb(t_stacks *s, int is_printable);
void	rr(t_stacks *s, int is_printable);
void	rra(t_stacks *s, int is_printable);
void	rrb(t_stacks *s, int is_printable);
void	rrr(t_stacks *s, int is_printable);
void	quicksort(int *array, int array_size);
int		check_array_sorted(int *array, int array_size);
int		check_unique_elements(int *array, int array_size);
int		check_integer(char *integer);
void	ft_puterror(void);
int		*initialize_array_of_integers(char **argv, int size);
void	initialize_stacks_structure(t_stacks *s, int argc, char **argv);
void	free_structure(t_stacks *s);
void	mini_sort(t_stacks *s);
void	full_sort(t_stacks *s);
int		find_max_index_in_array(int *array, int array_size);
int		find_min_index_in_array(int *array, int array_size);
void	define_rotations_for_index(t_stacks *s, t_rotations *rot, int pos_in_b);
int		process_instruction(t_stacks *s, char *inst);

#endif