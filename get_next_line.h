/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:19:11 by tmanolis          #+#    #+#             */
/*   Updated: 2021/07/05 18:41:49 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET_NEXT_LINE_H__
#define __GET_NEXT_LINE_H__

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

int		get_next_line(int fd, char **line);
char 	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
size_t  ft_strlen(const char *str);

#endif
