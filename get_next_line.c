/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:07:10 by rabril-h          #+#    #+#             */
/*   Updated: 2022/02/19 19:26:03 by rabril-h         ###   ########.bcn      */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clean_storage(char *storage, char *l)
{
	char *aux;

	if (rah_strlen_or_n(storage, '\0') == 0 && (rah_strlen_or_n(l, '\0') == 0))
	{
		free(storage);
		return (NULL);
	}
	else
	{
		aux = ft_substr(storage, (unsigned int)rah_strlen_or_n(storage, '\n'),
				(rah_strlen_or_n(storage, '\0') - rah_strlen_or_n(storage, '\n')));
	
		free(storage);
		return (aux);
	}
	
}

char	*get_line_from_storage(char *storage)
{
	char *line;
	
	line = ft_substr(storage, 0, (int)rah_strlen_or_n(storage, '\n'));
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
	storage = clean_storage(storage, line);
	if (rah_strlen_or_n(line, '\0') > 0)
		return (line);
	else
	{
		free (line);
		return (NULL);
	}
}
