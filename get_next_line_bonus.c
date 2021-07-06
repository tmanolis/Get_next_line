/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 17:51:30 by tmanolis          #+#    #+#             */
/*   Updated: 2021/07/06 18:00:56 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "get_next_line_bonus.h"

static char	*copy_until_EOL(char *stock)
{
	int		i;
	int		len;
	char	*line;

	i = 0;
	while (stock[i] != '\n' && stock[i] != '\0')
	{
		i++;
	}
	len = i;
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = stock[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static void	get_the_spare(char *buf)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buf[i] != '\n')
		i++;
	i = i + 1;
	while (i < BUFFER_SIZE)
	{
		buf[j] = buf[i];
		j++;
		i++;
	}
	buf[j] = '\0';
}

int	get_next_line_2(size_t ret, char *stock, char *buf, char **line)
{
	if (ret > 0)
	{
		*line = copy_until_EOL(stock);
		free(stock);
		get_the_spare(buf);
		return (1);
	}
	else
	{
		*line = copy_until_EOL(stock);
		free(stock);
		return (0);
	}
}

int	get_next_line(int fd, char **line)
{
	size_t		ret;
	static char	buf[1024][BUFFER_SIZE + 1];
	char		*stock;

	if (!line || BUFFER_SIZE <= 0 || read(fd, buf[fd], 0) == -1 )
		return (-1);
	stock = NULL;
	stock = ft_strjoin(stock, buf[fd]);
	ret = 1;
	while (ret > 0 && ft_strchr(stock, '\n') == 0)
	{
		ret = read(fd, buf[fd], BUFFER_SIZE);
		if (ret < 0)
		{
			free(stock);
			return (-1);
		}
		buf[fd][ret] = '\0';
		stock = ft_strjoin(stock, buf[fd]);
	}
	return (get_next_line_2(ret, stock, buf[fd], line));
}
