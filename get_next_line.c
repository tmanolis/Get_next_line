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
char	*ft_strchr(const char *s, int c);
char 	*ft_strjoin(char const *s1, char const *s2);
char    *ft_strdup(const char *s1);
void	*ft_memset(void *b, int c, size_t len);

void ft_putstr(char *s);

char	*initialize_stock(char *stock)
{
	int i;

	stock = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!stock)
		return (NULL);
	i = 0;
	while (i < BUFFER_SIZE)
	{
		stock[i] = '\0';
		i++;
	}
	return (stock);
}

char	*copy_until_EOF_2(char *line, char *stock, int i)
{
	line = (char *)malloc(sizeof(char) * (i + 1));
		if (!line)
			return (NULL);
	i = 0;
	while (stock[i] != '\n')
	{
		line[i] = stock[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

// char	*copy_until_EOF(char *buf, char *stock)
// {
// 	int i;
// 	char *line;

// // il faut peut etre gerer la size de stock qui fluctue avec un stock[j] ?
// 	i = 0;
// 	line = NULL;
// 	*stock = '\0';
// 	if (ft_strchr(stock, '\n') == 0)
// 	{
// 		ft_putstr("je suis dans le if de strchr\n");
// 		stock = ft_strjoin(stock, buf);
// 		ft_putstr("stock :");
// 		ft_putstr(stock);
// 		ft_putstr("\n");
// 	}
// 	while (stock[i] != '\n')
// 		i++;
// 	line = copy_until_EOF_2(line, stock, i);
// 	// if i < strlen(stock) il faut mettre le rest dans tmp;
// 	return (line);
//}

int get_next_line(int fd, char **line)
{
	char    	buf[BUFFER_SIZE + 1];
	ssize_t 	ret;
	static char	*stock;
	int i;

	ret = read(fd, buf, BUFFER_SIZE);
	ft_putstr("read ok\n");
	if (stock == NULL)
	stock = initialize_stock(stock);
	while (ret > 0 && ft_strchr(stock, '\n') == 0)
	{
		ft_putstr("je suis dans le if de strchr\n");
		stock = ft_strjoin(stock, buf);
		ft_putstr("stock :");
		ft_putstr(stock);			
		ft_putstr("\n");
		ret = read(fd, buf, BUFFER_SIZE);
	}
	i = 0;		
	while (stock[i] != '\n')
		i++;
	*line = copy_until_EOF_2(*line, stock, i);
	//ft_memset(stock, '\0', ft_strlen(stock));
	//ret = read(fd, buf, BUFFER_SIZE);
	//if (i < ft_strlen(stock)
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