/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:17:55 by tmanolis          #+#    #+#             */
/*   Updated: 2021/06/10 18:25:43 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

size_t  ft_strlen(const char *str);
size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
char *ft_strjoin(char const *s1, char const *s2);
char    *ft_strdup(const char *s1);

char	*copy_until_EOF(char *buf, char *stock)
{
	int i;
	char *line = NULL;

// il faut peut gerer la size de stock qui fluctue avec un stock[j] ?
	
	i = 0;
	*stock = '\0';
	while (ft_strchr(stock, '\n') == 0)
	{
		stock = ft_strjoin(stock, buf);

	}
	while (stock[i] != '\n')
	{
		// il faut malloc line avant donc strlen de stock jusqu'a '\n' pour la taille
		// du malloc de line.
		line[i] = stock[i];
		i++;
	}
	return (line);
}

int get_next_line(int fd, char **line)
{
    char    	buf[BUFFER_SIZE + 1];
    ssize_t 	ret;
	static char	*stock;

    ret = read(fd, buf, BUFFER_SIZE);
    while (ret > 0)
    {
        buf[ret] = '\0';
        *line = copy_until_EOF(buf, stock);
        ret = read(fd, buf, BUFFER_SIZE);
    }
	return (1);
}

int main(void)
{
    int		fd;
    char	*line;

    line = NULL;
	fd = open("test.txt", O_RDONLY);
    get_next_line(fd, &line);
	printf("|%s|\n", line);
	free(line);
	close (fd);
    return (0);
}