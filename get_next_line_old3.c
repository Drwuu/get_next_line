/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drwuu <drwuu@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:32:07 by ludwuu            #+#    #+#             */
/*   Updated: 2020/12/19 00:50:09 by drwuu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h" //to remove

int		new_line_index(char *str)
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

char	*copy_line(int fd, char *linecopy)
{
	char	buf[BUFFER_SIZE + 1];
	char	*str;
	char	*tmp;
	int		head;
	int		i;
	
	if(!(str = ft_strdup("")))
		return (NULL);
	if ((i = new_line_index(linecopy)) >= 0)
    {
        free(str);
		if(!(str = ft_substr(linecopy, i + 1, ft_strlen(linecopy))))
			return (NULL);
    }
	while ((i = new_line_index(str)) == -1)
	{
        if ((head = read(fd, buf, BUFFER_SIZE)) == 0)
        {
            free (linecopy);
            return (str);
        }
		buf[head] = '\0';
		if (!(tmp = ft_strjoin(str, buf)))
            return (NULL);
		free(str);
		str = tmp;
	}
    free (linecopy);
	return (str);
}

int		build_line(char *linecopy, char **line)
{
	int i;

	i = new_line_index(linecopy);
	//printf("i = %d\n", i);
	if (!(*line = ft_substr(linecopy, 0, i)))
		return (-1);
    if (i >= 0)
        return (1);
    else
    {
    	free(linecopy);
        return (0);
    }
}

int		get_next_line(int fd, char **line)
{
	static char *linecopy[4096];
	
	if (fd < 0 || line == NULL)
		return (-1);
	if (!linecopy[fd])
		if (!(linecopy[fd] = ft_strdup("")))
			return (-1);
	if (!(linecopy[fd] = copy_line(fd, linecopy[fd])))
		return (-1);
	return (build_line(linecopy[fd], line));
}