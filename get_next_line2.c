/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drwuu <drwuu@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:32:07 by ludwuu            #+#    #+#             */
/*   Updated: 2020/12/15 22:39:42 by drwuu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		new_line_index(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*copy_line(int fd, char *linecopy)
{
	char	buf[BUFFER_SIZE + 1];
	char	*str;
	int		head;
	int		i;
	
	if(!(str = ft_strdup("")))
		return (NULL);
	i = new_line_index(linecopy);
	if (linecopy[i] == '\n')
		if(!(str = ft_substr(linecopy, i + 1, ft_strlen(linecopy))))
			return (NULL);
	while ((head = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		i = new_line_index(buf);
		if (buf[i] == '\n')
		{
			str = ft_realloc(str, buf); // protection
			break;
		}
		buf[head] = '\0';
		str = ft_realloc(str, buf); // protection
		i = 0;
	}
	return (str);
}

int		build_line(char *linecopy, char **line)
{
	int i;

	i = new_line_index(linecopy);
	if (!(*line = ft_substr(linecopy, 0, i)))
		return (0);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char *linecopy;
	
	if (fd < 0 || line == NULL)
		return (-1);
	if (!linecopy)
		if (!(linecopy = malloc(sizeof(*linecopy) * (BUFFER_SIZE + 1))))
			return (-1);
	if (!(linecopy = copy_line(fd, linecopy)) 	\
			|| !(build_line(linecopy, line)))
		return (-1);
	if (linecopy[ft_strlen(linecopy) - 1])
		return (1);
	free(linecopy);
	return (0);
}
