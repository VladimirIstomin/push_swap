/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:37:22 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/07 17:54:29 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			count++;
		else if (i != 0 && s[i - 1] == c && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

static size_t	get_word_length(char const *s, size_t start, char c)
{
	size_t	i;

	i = 0;
	while (s[start + i])
	{
		if (s[start + i] == c)
			return (i);
		i++;
	}
	return (i);
}

static char	**free_array_of_chars(char **array, size_t end)
{
	size_t	i;

	i = 0;
	while (i < end)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

static size_t	get_next_word_index(char const *s, size_t start, char c)
{
	while (s[start] == c)
		start++;
	return (start);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	strs = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!strs)
		return (NULL);
	while (i < count_words(s, c))
	{
		j = get_next_word_index(s, j, c);
		len = get_word_length(s, j, c);
		strs[i] = ft_substr(s + j, 0, len);
		if (!strs[i])
			return (free_array_of_chars(strs, i));
		j += len;
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
