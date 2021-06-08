/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 17:25:08 by tmanolis          #+#    #+#             */
/*   Updated: 2021/06/08 13:56:00 by tmanolis         ###   ########.fr       */
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