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
	int	max_size;
}		t_stacks;

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

# define ERROR_DUPLICATES "Some integers are duplicated."
# define ERROR_NOT_INTEGER "The input doesn't just consist of integers."
# define ERROR_INTEGER_OVERFLOW "Some numbers are not integers due to overflow."
# define ERROR_NO_ARGS "No arguments were passed."
# define ERROR_STACK_ALLOCATION "Unable to allocate memory for stacks."

void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ss(t_stacks *stacks);
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);
void	ra(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rr(t_stacks *stacks);
void	rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	rrr(t_stacks *stacks);
int		get_stack_size(int *stack, int stack_max_size);
void	quicksort(int *array, int array_size);
int		check_array_sorted(int *array, int array_size);
int		check_unique_elements(int *array, int array_size);
int		check_integer(char *integer);
void	ft_puterror(char *error);
int		*initialize_array_of_integers(char **argv, int max_size);
void	initialize_stacks_structure(t_stacks *stacks, char **argv);
void	free_structure(t_stacks *stacks);

#endif