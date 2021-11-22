/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:53:14 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/22 19:57:52 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_stack_size(int *stack, int stack_max_size)
{
	int	i;

	i = 0;
	while (stack[i] && i < stack_max_size)
		i++;
	return (i);
}
