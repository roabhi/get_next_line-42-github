/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:07:10 by rabril-h          #+#    #+#             */
/*   Updated: 2022/02/18 22:07:19 by rabril-h         ###   ########.bcn      */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	get_line_cnt(const char *storage)
{
	size_t i;

	i = 0;
	while (storage[i] != '\n' && storage[i])
		i++;
	return (i + 1);
}

char	*clean_storage(char *storage)
{
	char *aux;

	aux = storage;
	storage = ft_substr(storage, (unsigned int)get_line_cnt(storage), (ft_strlen(storage) - get_line_cnt(storage)));
	free(aux);
	return (storage);
}


char	*get_line_from_storage(char *storage)
{
	char *line;
	
	line = ft_substr(storage, 0, (int)get_line_cnt(storage));
	return (line);
}


char	*get_next_line(int fd)
{

	char 		*line;
	static char	*storage = NULL;
	int 		rb;
	char 		*buffer;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);	
	rb = 1;	
	while (rb > 0 && (!ft_strchr(storage, '\n')))
	{
		rb = read(fd, buffer, BUFFER_SIZE);
		if (rb == -1 || rb == 0)
			break;
		buffer[rb] = '\0';
		if (storage == NULL)
			storage = ft_strdup(buffer);
		else
			storage = ft_strjoin(storage, buffer);
	}
	free(buffer);
	if (rb == -1)
		return (NULL);
	if (rb == 0 && storage == NULL)
		return (NULL);
	line = get_line_from_storage(storage);
	storage = clean_storage(storage);
	return (line);
}
