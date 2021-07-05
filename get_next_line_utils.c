/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 17:25:08 by tmanolis          #+#    #+#             */
/*   Updated: 2021/07/05 18:19:27 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

#include <unistd.h>
#include <stdio.h>

size_t  ft_strlen(const char *str)
{
        int i;

		if (!str)
			return (0);
        i = 0;
        while (str[i] != '\0')
                i++;

        return (i);
}

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0' && *s == c)
		return ((char *)s);
	else
		return (0);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dst;

	i = 0;
	dst = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dst)
		return (NULL);
	while(s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char 	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	i = 0;
	j = 0;
	if (s1 == NULL)
		return (ft_strdup(s2));
	new_str = (char	*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
  	if (!new_str)
		return (NULL);
	while (s1[i])
	{
		new_str[j++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		new_str[j++] = s2[i++];
	}
	new_str[j] = '\0';
	free(s1);
	return (new_str);
}