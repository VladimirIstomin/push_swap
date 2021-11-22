/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:37:12 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/15 09:44:35 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*strf;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = len;
	strf = malloc(sizeof(char) * (len + 1));
	if (!strf)
		return (NULL);
	strf[i--] = '\0';
	while (i <= len)
	{
		strf[i] = f(i, s[i]);
		i--;
	}
	return (strf);
}
