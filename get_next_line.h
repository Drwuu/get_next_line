/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludwuu <ludwuu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:05:04 by ludwuu            #+#    #+#             */
/*   Updated: 2020/12/04 02:09:53 by ludwuu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

int     get_next_line(int fd, char **line);
char	*ft_realloc(char *s1, const char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
