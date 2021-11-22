/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:33:12 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/07 18:08:31 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	clear_node_chain(t_list *node, void (*del)(void *))
{
	if (node->next)
		clear_node_chain(node->next, del);
	del(node->content);
	free(node);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (lst && *lst)
	{
		clear_node_chain(*lst, del);
		*lst = NULL;
	}
}
