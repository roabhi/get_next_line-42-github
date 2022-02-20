/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:54:28 by rabril-h          #+#    #+#             */
/*   Updated: 2022/02/19 19:15:51 by rabril-h         ###   ########.bcn      */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char	*get_next_line(int fd);
// size_t	ft_strlen(const char *s);
size_t	get_line_cnt(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	*ft_calloc(size_t count, size_t size);
size_t  rah_strlen_or_n(const char *s, char c);
	
#endif

