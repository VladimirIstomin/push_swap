/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:40:53 by gmerlene          #+#    #+#             */
/*   Updated: 2021/12/02 15:58:38 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_only_digits(char *integer)
{
	int	i;

	i = 0;
	if (integer[i] == '-' && ft_isdigit(integer[i + 1]))
		i += 2;
	while (integer[i])
	{
		if (!ft_isdigit(integer[i]))
		{
			ft_puterror(ERROR_NOT_INTEGER);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	check_integer_no_overflow(char *integer)
{
	int		int_len;
	char	*intcmp;
	int		intcmp_len;
	int		is_no_overflow;

	is_no_overflow = 1;
	if (integer[0] == '-')
		intcmp = ft_itoa(INT_MIN);
	else
		intcmp = ft_itoa(INT_MAX);
	int_len = ft_strlen(integer);
	intcmp_len = ft_strlen(intcmp);
	if (int_len > intcmp_len)
		is_no_overflow = 0;
	else if (int_len == intcmp_len && ft_strncmp(integer, intcmp, int_len) > 0)
		is_no_overflow = 0;
	if (!is_no_overflow)
		ft_puterror(ERROR_INTEGER_OVERFLOW);
	free(intcmp);
	return (is_no_overflow);
}

int	check_integer(char *integer)
{
	if (!check_only_digits(integer))
		return (0);
	if (!check_integer_no_overflow(integer))
		return (0);
	return (1);
}
