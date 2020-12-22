/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drwuu <drwuu@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 19:01:43 by drwuu             #+#    #+#             */
/*   Updated: 2020/12/21 00:18:00 by drwuu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h" //to remove

int		find_newline(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		copy_line(const char *buf, char **str)
{
	char	*tmp;
	
	if (!*str)
	{
		if (!(*str = ft_strdup(buf)))
			return (-1);
	}
	else
	{
		if (!(tmp = ft_strjoin(*str, buf)))
			return (-1);
		free(*str);
		*str = tmp;
	}
	return (1);
}

int		read_line(char **str, int fd)
{
	int		head;
	char	*buf;

	if (!(buf = malloc(sizeof(*buf) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((head = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[head] = '\0';
		if (copy_line(buf, str) < 0)
			return (-1);
		if (find_newline(*str) >= 0)
			break ;
	}
	if (head < 0)
		return (-1);
	if (!*str)
		if(!(*str = ft_strdup("")))
			return (-1);
	free(buf);
	return (1);
}

int		build_line(char **str, char **line)
{
	int		i;
	char	*tmp;

	i = find_newline(*str);
	if (i >= 0)
	{
		if (!(*line = ft_substr(*str, 0, i)))
			return (-1);
		if (!(tmp = ft_strdup(&(*str)[i + 1])))
			return (-1);
		free(*str);
		*str = tmp;
		return (1);
	}
	else
	{
		if (!(*line = ft_substr(*str, 0, ft_strlen(*str))))
			return (-1);
		free(*str);
		*str = NULL;
		return (0);
	}
}

int		get_next_line(const int fd, char **line)
{
	static char	*str[7777];
	
	if (!line || fd < 0)
		return (-1);
	if (read_line(&str[fd], fd) > 0)
		return (build_line(&str[fd], line));
	else
		return (-1);
}
