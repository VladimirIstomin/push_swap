/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:18:25 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/08 17:54:20 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *initial_ptr, size_t initial_size, size_t new_size)
{
	void	*new_ptr;

	new_ptr = ft_calloc(1, new_size);
	if (new_ptr)
		ft_memmove(new_ptr, initial_ptr, initial_size);
	free(initial_ptr);
	initial_ptr = NULL;
	return (new_ptr);
}
