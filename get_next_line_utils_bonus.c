/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:13:17 by ludwuu            #+#    #+#             */
/*   Updated: 2020/12/16 18:32:37 by lwourms          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i]) 
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	if (!(str = malloc(sizeof(*str) * (ft_strlen((char *)s1) + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	if (!(str = malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	if ((size_t)start >= ft_strlen((char *)s))
	{
		str[0] = '\0';
		return ((char *)str);
	}
	i = 0;
	j = start;
	while (j < start + (unsigned int)len && s[j])
		str[i++] = s[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_realloc(char *s1, const char *s2, int s2len)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + s2len;
	//printf("len = %d\n", len);
	if (!(str = malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	free(s1);
	j = i;
	i = 0;
	while (i <= s2len)
	{
		//printf("coucou\n");
		str[j++] = s2[i++];
	}
	str[j] = '\0';
	return (str);
}
