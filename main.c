/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:33:34 by rabril-h          #+#    #+#             */
/*   Updated: 2022/02/19 17:09:00 by rabril-h         ###   ########.bcn      */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main()
{
	char *line;
	int	f;	

	//f = open("tests/test.txt", O_RDONLY);
	f = open("tests/test2.txt", O_RDONLY);
	//f = open("tests/test3.txt", O_RDONLY);
	//f = open("tests/test4.txt", O_RDONLY);
	//f = open("tests/empty.txt", O_RDONLY);
	//f = open("tests/1char.txt", O_RDONLY);
	//f = open("tests/nl.txt", O_RDONLY);
	line = get_next_line(f);
	//line = get_next_line("soy un string")
	//printf("line [%02d]: %s", f, line);
	printf("++++++++++++++++++++\n");
	printf("linea es \n\n %s\n\n",line);
	free(line);
	printf("++++++++++++++++++++\n");
	line = get_next_line(f);
	printf("linea es \n\n %s", line);
	free(line);
	printf("++++++++++++++++++++\n");
	line = get_next_line(f);
	printf("linea es \n\n %s", line);
	free(line);
	printf("++++++++++++++++++++\n");
	line = get_next_line(f);
	printf("linea es \n\n %s", line);
	free(line);
	printf("++++++++++++++++++++\n");
	line = get_next_line(f);
	printf("linea es \n\n %s", line);
	free(line);
	printf("++++++++++++++++++++\n");
	line = get_next_line(f);
	printf("linea es \n\n %s", line);
	free(line);
	printf("++++++++++++++++++++\n");
	line = get_next_line(f);
	printf("linea es \n\n %s", line);
	free(line);
	printf("++++++++++++++++++++\n");
	line = get_next_line(f);
	printf("linea es \n\n %s", line);
	free(line);
	printf("++++++++++++++++++++\n");
	line = get_next_line(f);
	printf("linea es \n\n %s", line);
	free(line);
	printf("++++++++++++++++++++\n");
	line = get_next_line(f);
	printf("linea es \n\n %s", line);
	free(line);
	return (0);
}
