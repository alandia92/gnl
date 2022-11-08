/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlandia <arlandia@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:53:14 by arlandia          #+#    #+#             */
/*   Updated: 2022/11/08 16:09:21 by arlandia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/fcntl.h>
#include "stdio.h"
#include "get_next_line.h


char	*ft_getline(char *save)
{
	int		i;
	char	*line;

	i = 0;
	if (!save)
		return (NULL);
	i = ft_strlen(save);
	line = malloc (sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i])
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		line[i] = '\n';
		line[i + 1] = '\0';
	}
	else if (save[i] == '\0')
		line[i] = '\0';
	return (line);
}

char *ft_restline(char *line)
{
	int i;
	int j;
	char *rest;

	if (!line)
		return (NULL);
	i = ft_countline(line);
	rest = malloc(sizeof (char) * ft_strlen(line) - i);
	if (!rest)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		rest[j++] = line[i++];
	rest[j] ='\0';
	return (rest);
}

char *ft_readline(int fd, char *line)
{
	char	*aux;
	int		i;

	aux = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!aux)
		return (NULL);
	i = 1;
	while (!ft_strchr(line, '\n') && i != 0)
	{
		i = read(fd, aux, BUFFER_SIZE);
		if (i == -1)
			return (free (aux), NULL);
		aux[i] = '\0';
		line = ft_strjoin(line, aux);
	}
	free (aux);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*saveread;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	saveread = ft_readline(fd, line);
	if (!saveread)
		return (NULL);
	line = ft_getline(saveread);
	return (line);
}

int	main()
{
	int fd;
	char *line;
 	fd = open("text.txt", O_RDONLY);
	line = get_next_line(fd);
	while(line)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	close(fd);
}
