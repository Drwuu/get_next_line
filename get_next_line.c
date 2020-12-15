/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludwuu <ludwuu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:32:07 by ludwuu            #+#    #+#             */
/*   Updated: 2020/12/04 22:16:26 by ludwuu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *old_fillstr(int fd, char *str)
{
    char    buf[BUFFER_SIZE + 1];
    int     head;

    while ((head = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        buf[head] = '\0';
        str = ft_realloc(str, buf);
    }
    return (str);
}

int     readline(int fd, char *str)
{
    char        buf[BUFFER_SIZE + 1];
    int         head;
    int static  i = 0;

    while ((head = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        buf[head] = '\0';
        str = ft_realloc(str, buf);
        while (str[i])
    }
    return (0);
}

int    build_line(char *str, char **line)
{
    int         start;
    static int  i = 0;

    start = i;
    while (str[i] && str[i] != '\n')
        i++;
    *line = ft_substr(str, start, i - start);
    printf("next line = %s\n", *line);
    printf("str c = %d\n", str[i]);
    if (str[i])
    {
        i++;
        return (1);
    }
    else
        return (0);
}

int     get_next_line(int fd, char **line)
{
    static char *str;

    if (fd < 0 || line == 0)
        return (-1);
    if (!str)
    {
        if (!(str = malloc(sizeof(*str) * BUFFER_SIZE + 1)))
            return (-1);
        str = fillstr(fd, str);
    }
    if (build_line(str, line))
        return (1);
    free(str);
    return (0);
}
