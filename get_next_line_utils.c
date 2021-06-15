/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 17:25:08 by tmanolis          #+#    #+#             */
/*   Updated: 2021/06/10 17:49:09 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

#include <unistd.h>

size_t  ft_strlen(const char *str)
{
        int i;

        i = 0;
        while (str[i] != '\0')
                i++;

        return (i);
}

char	*ft_strchr(const char *s, int c)
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

char *ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
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
	return (new_str);
}

void ft_putstr(char *s)
{
    if (s)
    {
    size_t  len;

    len = ft_strlen(s);
    write(1, s, len);
    }
}