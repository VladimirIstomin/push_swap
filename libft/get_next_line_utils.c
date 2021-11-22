/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:46:35 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/11 16:42:17 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_strlen_protected(char *str)
{
	if (!str)
		return (0);
	return (ft_strlen(str));
}

static char	*join_strings_in_memory(char *memory, char *str1, char *str2)
{
	int		i;
	int		j;
	int		len_str1;
	int		len_str2;

	i = 0;
	j = 0;
	len_str1 = ft_strlen_protected(str1);
	len_str2 = ft_strlen_protected(str2);
	while (i < len_str1)
	{
		memory[i] = str1[i];
		i++;
	}
	while (j < len_str2)
	{
		memory[i + j] = str2[j];
		j++;
	}
	memory[i + j] = '\0';
	return (memory);
}

char	*join_strings(char *str1, char *str2)
{
	int		len_str1;
	int		len_str2;
	char	*new_str;

	len_str1 = ft_strlen_protected(str1);
	len_str2 = ft_strlen_protected(str2);
	new_str = malloc(sizeof(char) * (len_str1 + len_str2 + 1));
	if (!new_str)
		return (NULL);
	new_str = join_strings_in_memory(new_str, str1, str2);
	if (str1)
		free(str1);
	return (new_str);
}

int	get_nl_index(char *line)
{
	int	i;

	if (!line)
		return (-1);
	i = 0;
	while (i < (int)ft_strlen(line))
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	unshift_line(char *line)
{
	int		i;
	int		nl_index;

	if (!line)
		return ;
	nl_index = get_nl_index(line);
	if (nl_index == -1)
		return ;
	i = 0;
	while (nl_index + i + 1 < (int)ft_strlen(line))
	{
		line[i] = line[nl_index + i + 1];
		i++;
	}
	line[i] = '\0';
}
