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

	while (stock[i] != '\n')
	{	
		// stock = "hello\n prout"
		// il faut malloc line avant donc strlen de stock jusqu'a '\n' pour la taille
		// du malloc de line.
		i++;
	}
	// i = le nombre de charactere jusqua \n
	// adresse de &i - &stock = taille
	
	// on malloc line a la taille de i + 1 
	// str_n_copy() (source: stock, des: line, n: i)
	str_n_copy(line, stock, i) // on part du principe pour l exemple que copy malloc
	

	// stock = "hello\nhihi"
	// transformation pif paf
	// stock = "hihi"

	// renvoie l address de line
	return (line);
}

int get_next_line(int fd, char **line)
{
    char    	buf[BUFFER_SIZE + 1];
    ssize_t 	ret;
	static char	*stock;

	// faut malloc buf ""
	// "hello" & BUFFER_SIZE = 2 => buf = "he" 
	// "hello" & BUFFER_SIZE = 7 => buf = "hello\0\0" 
	// "hello" & BUFFER_SIZE = 1000 => buf = "hello\0\0...\0" est ce que c est free?
	

    ret = read(fd, buf, BUFFER_SIZE); 
    while (ret > 0 && ft_strchr(buf, '\n') == 0)
    {	
		
		// tant qu'on ne trouve pas de \n on ajoute buf a la suite de stock
		stock = ft_strjoin(stock, buf); // y a une libft join qui malloc
	
		ret = read(fd, buf, BUFFER_SIZE);
		// est ce utile buf[ret] ?
		buf[ret] = '\0'; // verifier que ca permet de free jusqu'au bout 
    }

	
	// verifier qu'il y a bien rien dans buf et si il y a alors l'ajouter a stock
	// buffer = "\nhihi"
	// stock = "haha"
	// faut mettre buffer dans stock

	// stock = "haha\nhihi"
	if (strlen(stock) > 0) {
		*line = copy_until_EOF(stock); // get the following line
	}
	else {
		return (0)
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