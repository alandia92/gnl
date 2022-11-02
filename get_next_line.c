/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlandia <arlandia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:37:12 by arrate            #+#    #+#             */
/*   Updated: 2022/11/02 20:38:42 by arlandia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

char	get_next_line(int fd)
{
	char*	line;
	int		i;
	char	*aux;
	static char	*rest;
	if (fd < 0 || read(fd,0,0) < 0)
		return(NULL);
	while (true)
	{
	i = read(fd, aux, BUFFER_SIZE);
	if (i != BUFFER_SIZE)
	{
		if(!i && *line)
			return (line);
		if(!i && !*line)
			return (NULL);
		if(ft_strchr(aux, '\n'))
			return(ft_strjoin(line, ft_subtring(aux, rest)));
		if (!ft_strchr(aux, '\n'))
			return(ft_strjoin(line, aux));
	}
	if (ft_strchr(aux, '\n'))
		return(ft_strjoin(line, ft_subtring(aux, rest)));
	line = ft_strjoin(line, aux);
	}
}

// char	ft_getline(char *save)
// {
// 	int		i;
// 	char	*line;

// 	i = 0;
// 	if (!save)
// 		return (NULL);
// 	i = ft_strlen(save);
// 	line = malloc (sizeof(char) * (i + 2));
// 	if (!line)
// 		return (NULL);
// 	i = 0;
// 	while (save[i])
// 	{
// 		line[i] = save[i];
// 		i++;
// 	}
// 	if (save[i] = '\n')
// 	{
// 		line[i] = '\n';
// 		line[i + 1] = '\0';
// 	}
// 	else if (save[i] = '\0')
// 		line[i] = '\0';
// 	return (line);
// }

// char	*ft_read(int fd, char *save)
// {
	
// }

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
