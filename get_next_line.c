/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlandia <arlandia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:53:14 by arlandia          #+#    #+#             */
/*   Updated: 2022/11/21 19:07:18 by arlandia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *save)
{
	int		i;
	char	*line;

	i = 0;
	if (!save[i])
		return (NULL);
	i = ft_countline(save);
	line = malloc (sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
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

char	*ft_restline(char *line)
{
	int		i;
	int		j;
	char	*rest;

	i = ft_countline(line);
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	rest = malloc(sizeof(char) * (ft_strlen(line) - i));
	if (!rest)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		rest[j++] = line[i++];
	rest[j] = '\0';
	free(line);
	return (rest);
}

char	*ft_readline(int fd, char *line)
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
		{
			free (aux);
			return (NULL);
		}
		if (i == 0)
			break ;
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
	saveread = ft_readline(fd, saveread);
	if (!saveread)
		return (NULL);
	line = ft_get_line(saveread);
	saveread = ft_restline(saveread);
	return (line);
}
