/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:17:55 by tmanolis          #+#    #+#             */
/*   Updated: 2021/06/07 19:55:46 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
    char    buf[BUFFER_SIZE + 1];
    ssize_t ret;

    ret = read(fd, buf, BUFFER_SIZE);
    while (ret > 0)
    {
        buf[ret] = '\0';
        *line = strdup(buf);
        ret = read(fd, buf, BUFFER_SIZE);
		ret = 0;
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