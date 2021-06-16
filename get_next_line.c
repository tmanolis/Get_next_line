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

char	*copy_until_EOF(char *line, char *stock, size_t i)
{
	size_t	len;
	
	line = (char *)malloc(sizeof(char) * (i + 1));
		if (!line)
			return (NULL);
	i = 0;
	len = ft_strlen(stock); // to handle the last line of the file
	while (stock[i] != '\n' && i < len)
	{
		line[i] = stock[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
char	*copy_rest(char	*stock, size_t i)
{
	size_t	j;
	size_t	len;
	char	*tmp;

	len = ft_strlen(stock) - i;
	tmp = (char *)malloc(sizeof(char) * len);
	if (!tmp)
		return (NULL);
	j = 0;
	i = i + 1;
	while (i < ft_strlen(stock))
	{
		tmp[j] = stock[i];
		j++;
		i++;
	}
	tmp[j] = '\0';
	return (tmp);
}

size_t	len_of_line(size_t ret, char *stock)
{
	size_t i;

	i = 0;
	if (ret == 0 && ft_strchr(stock, '\n') == 0) // 2nd condition to deal with the last line
		i = ft_strlen(stock);
	else 
	{
		while (stock[i] != '\n')
			i++;
	}
	return (i);
}

int get_next_line(int fd, char **line)
{
	size_t		i;
	size_t		ret;
	char    	buf[BUFFER_SIZE + 1];
	char		*tmp;
	static char	*stock;

	ret = read(fd, buf, BUFFER_SIZE);
	buf[ret] = '\0';
	if (stock == NULL)
		stock = initialize_stock(stock);
	while (ret > 0 && ft_strchr(stock, '\n') == 0)
	{
		stock = ft_strjoin(stock, buf);
		if (ret != 0)
		{
			ret = read(fd, buf, BUFFER_SIZE);
			buf[ret] = '\0';
		}
	}
	i = len_of_line(ret, stock);
	*line = copy_until_EOF(*line, stock, i);
	tmp = NULL;
	if (i < ft_strlen(stock))
	{
		tmp = copy_rest(stock, i);
		free (stock);
		stock = tmp;
	}
	stock = ft_strjoin(stock, buf);
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
	get_next_line(fd, &line);
	printf("|%s|\n", line);
	free(line);
	get_next_line(fd, &line);
	printf("|%s|\n", line);
	free(line);
	get_next_line(fd, &line);
	printf("|%s|\n", line);
	free(line);
	close (fd);
	return (0);
}
