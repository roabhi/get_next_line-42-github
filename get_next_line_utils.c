/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:16:05 by rabril-h          #+#    #+#             */
/*   Updated: 2022/02/19 19:16:06 by rabril-h         ###   ########.bcn      */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	char	*x;
	size_t	j;

	ptr = (void *)malloc(count * size);
	j = 0;
	x = (char *)ptr;
	if (!ptr)
		return (NULL);
	while (j < (count * size))
	{
		x[j] = 0;
		j++;
	}
	return ((void *)ptr);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (i < (dstsize - 1) && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	c;
	char	*str;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_calloc(1, 1));
	c = ft_strlen(s);
	if (len > c)
		len = c;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}


char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != (unsigned char)c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)s + i);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);	
}

char	*ft_strdup(const char *s1)
{
	int		c;
	char	*str;

	c = 0;
	str = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!str)
		return (NULL);
	while (s1[c] != '\0')
	{
		str[c] = s1[c];
		c++;
	}
	str[c] = '\0';
	return ((char *)str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		c;
	int		i;

	c = 0;
	i = 0;
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[c] != '\0')
	{
		str[c] = s1[c];
		c++;
	}
	while (s2[i] != '\0')
	{
		str[c + i] = s2[i];
		i++;
	}
	str[c + i] = '\0';
	free(s1);
	return (str);
}
