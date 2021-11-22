/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:46:32 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/13 16:48:37 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	free_buffer(int rb, char *buff)
{
	if (buff)
		free(buff);
	return (rb);
}

static int	read_until_nl(int fd, char **lines)
{
	int		rb;
	char	*buff;

	rb = 0;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	buff[0] = '\0';
	if (get_nl_index(lines[fd]) == -1)
	{
		while (get_nl_index(buff) == -1)
		{
			rb = read(fd, buff, BUFFER_SIZE);
			if (rb <= 0)
				return (free_buffer(rb, buff));
			buff[rb] = '\0';
			lines[fd] = join_strings(lines[fd], buff);
			if (!lines[fd])
				return (free_buffer(rb, buff));
		}
	}
	return (free_buffer(rb, buff));
}

static char	*extract_line(char *line)
{
	int		nl_index;
	int		len;
	char	*extracted;
	int		i;

	if (!line || !ft_strlen(line))
		return (NULL);
	nl_index = get_nl_index(line);
	if (nl_index == -1)
		len = ft_strlen(line);
	else
		len = nl_index + 1;
	extracted = malloc(sizeof(char) * (len + 1));
	if (!extracted)
		return (NULL);
	i = 0;
	while (i < len)
	{
		extracted[i] = line[i];
		i++;
	}
	extracted[i] = '\0';
	return (extracted);
}

char	*get_next_line(int fd)
{
	static char	*lines[OPEN_MAX + 1];
	char		*res;
	int			rb;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	rb = read_until_nl(fd, lines);
	res = extract_line(lines[fd]);
	if ((get_nl_index(lines[fd]) == -1 && rb <= 0) || (lines[fd] && !res))
	{
		free(lines[fd]);
		lines[fd] = NULL;
	}
	unshift_line(lines[fd]);
	return (res);
}
