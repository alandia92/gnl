/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlandia <arlandia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:37:12 by arrate            #+#    #+#             */
/*   Updated: 2022/11/02 16:50:53 by arlandia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	get_next_line(int fd)
{
}

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
