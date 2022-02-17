/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:07:10 by rabril-h          #+#    #+#             */
/*   Updated: 2022/02/17 21:56:50 by rabril-h         ###   ########.bcn      */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//int	ft_nlinstr(char *storage)
//{
//	size_t	l;

//	l = ft_strlen(ft_strchr(storage, '\n'));
//	return ((int)l);
//}





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
	static char	*storage="";
	int 		read_bytes;
	char 		*buffer;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);	
	read_bytes = 1;	
	while (read_bytes > 0 && (!ft_strchr(storage, '\n')))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}		
		buffer[read_bytes] = '\0';
		storage = ft_strjoin(storage, buffer);	
	}
	//cuando salgo aqui en almacen tengo \n  0 \0
	//tengo que poner en una linea la rimera linea que encuentre en almacen o todo e almacen si no hay \n dentro
	//free(buffer);
	line = get_line_from_storage(storage);
	//limpio del almacen lo que he pasado a la linea y me quedo solo con lo que quiero guardr
	storage = clean_storage(storage);


	//printf("++++++++++++++++++++\n");
	//printf("Mi storage antes de devolver linea es \n %s \n\n", storage);

	return (line);//linea
}
