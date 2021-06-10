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

size_t  ft_strlen(const char *str)
{
        int i;

        i = 0;
        while (str[i] != '\0')
                i++;

        return (i);
}

size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
        size_t  i;

        i = 0;
        if (dstsize == 0)
                return (ft_strlen(src));
        if (src == NULL)
                return (0);
        while (src[i] && i < dstsize - 1)
        {
                dst[i] = src[i];
                i++;
        }
        dst[i] = '\0';
        return (ft_strlen(src));
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

char    *ft_strdup(const char *s1)
{
        int             len;
        char    *dst;

        len = ft_strlen(s1);
        dst = malloc(sizeof(char) * (len + 1));
        if (!dst)
                return (NULL);
        ft_strlcpy(dst, s1, len + 1);
        return (dst);

}