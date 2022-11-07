/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlandia <arlandia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:37:12 by arrate            #+#    #+#             */
/*   Updated: 2022/11/07 17:05:46 by arlandia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	ft_getline(char *save)
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
	if (save[i] = '\n')
	{
		line[i] = '\n';
		line[i + 1] = '\0';
	}
	else if (save[i] = '\0')
		line[i] = '\0';
	return (line);
}

char ft_readline(int fd, char *line)
{
	char	*aux;
	int		i;

	aux = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!aux)
		return (NULL);
	i = 1;
	while (ft_strchr(line, '\n') && i != 0)
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

char	get_next_line(int fd)
{
	char		*line;
	static char	*saveread;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saveread = ft_readline(fd, );
	if (!saveread)
		return (NULL);
	line = ft_getline(saveread);
	return (line);
}

// int	main()
// {
// 	int fd;
// 	char *line;
// 	fd = open("text.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	while(line)
// 	{
// 		printf("%s", line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// }
