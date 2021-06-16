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

char	*copy_until_EOF(char *line, char *stock, size_t i)
{
	size_t	len;

	ft_putstr("je suis dans le copy_until_EOF\n");
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

int get_next_line(int fd, char **line)
{
	size_t		i;
	size_t		ret;
	char    	buf[BUFFER_SIZE + 1];
	char		*tmp;
	static char	*stock;

	ret = read(fd, buf, BUFFER_SIZE);
	buf[ret] = '\0';
	ft_putstr("read ok\n");
	if (stock == NULL)
		stock = initialize_stock(stock);
	while (ret > 0 && ft_strchr(stock, '\n') == 0)
	{
		ft_putstr("je suis dans le if de strchr\n");
		ft_putstr("buf : ");
		ft_putstr(buf);
		ft_putstr("\n");
		stock = ft_strjoin(stock, buf);
		ft_putstr("stock apres strjoin : ");
		ft_putstr(stock);			
		ft_putstr("\n");
		if (ret != 0)
		{
			ret = read(fd, buf, BUFFER_SIZE);
			buf[ret] = '\0';
		}
	}
	printf("ret : %zu\n", ret);
	i = 0;
	if (ret != 0)
	{		
		while (stock[i] != '\n') // 2nd condition to deal with the last line
		i++;
	}
	else 
	{
		i = ft_strlen(stock);
		printf("i : %zu\n", i);
	}
	*line = copy_until_EOF(*line, stock, i);
	
	ft_putstr("line : ");
	ft_putstr(*line);		
	ft_putstr("\n");
	ft_putstr("stock apres copier dans line : ");
	ft_putstr(stock);			
	ft_putstr("\n");
	printf("i : %zu\n", i);
	printf("strlen(stock) : %zu\n", ft_strlen(stock));
	
	tmp = NULL;
	if (i < ft_strlen(stock))
	{
		tmp = copy_rest(stock, i);
		free (stock);
		stock = tmp;
		ft_putstr("stock apres free + tmp : ");
		ft_putstr(stock);
		ft_putstr("\n");
	}
	ft_putstr("buf : ");
	ft_putstr(buf);
	ft_putstr("\n");
	stock = ft_strjoin(stock, buf);
	ft_putstr("stock apres free + join : ");
	ft_putstr(stock);
	ft_putstr("\n");
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
	get_next_line(fd, &line);
	printf("|%s|\n", line);
	get_next_line(fd, &line);
	printf("|%s|\n", line);
	close (fd);
	return (0);
}

// à la fin du read 