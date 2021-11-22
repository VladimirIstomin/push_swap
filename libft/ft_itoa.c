/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:37:38 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/08 20:18:09 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static short int	get_num_len(int n)
{
	short int	num_len;

	num_len = 0;
	if (n <= 0)
		num_len++;
	while (n != 0)
	{
		n /= 10;
		num_len++;
	}
	return (num_len);
}

unsigned int	ft_abs(int n)
{
	unsigned int	abs;

	if (n < 0)
		abs = -n;
	else
		abs = n;
	return (abs);
}

char	*ft_itoa(int n)
{
	short int	num_len;
	char		*str;
	short int	i;

	num_len = get_num_len(n);
	str = malloc(sizeof(char) * (num_len + 1));
	if (!str)
		return (NULL);
	i = num_len;
	str[i--] = '\0';
	if (n < 0)
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[i] = ft_abs(n % 10) + '0';
		n /= 10;
		i--;
	}
	return (str);
}
