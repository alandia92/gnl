/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlandia <arlandia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:39:30 by arrate            #+#    #+#             */
/*   Updated: 2022/11/07 18:06:19 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == (c % 256))
			return ((char *)&s[i]);
	}
	if (s[i] == (c % 256))
		return ((char *)&s[i]);
	return (NULL);
}

size_t 	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s [i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*str;
	size_t i;

	i = 0;
	if (!s1)
		return (NULL);
	while (s1[i])
		i++;
	str = malloc(sizeof (char) * s1[i+1]);
	if (!str)
		return (free (s1), NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	free(s1);
	return (&str[i]);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int	i;
	int	j;
	int		len;
	char	*str;

	len = ft_strlen(s1) + ft_strlen(s2);
	if (!s1 && !s2)
		return (NULL);
	str = malloc (sizeof (char) * (len + 1));
	if (!str)
		return (free (s1), NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = 0;
	while (s2[j])
		str[i++] = s2 [j++];
	str[len] = 0;
	free (s1);
	//free(s2);
	return (str);
}

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*copy;
// 	size_t	i;

// 	if (len > (size_t)ft_strlen(s))
// 		len = (size_t)ft_strlen(s);
// 	if (start > (unsigned int)ft_strlen(s))
// 		start = ft_strlen(s);
// 	copy = (char *)malloc(sizeof(char) * (len + 1));
// 	if (copy == 0)
// 		return (0);
// 	i = 0;
// 	while (s[i + start] && len)
// 	{
// 		copy[i] = s[i + start];
// 		i++;
// 		len--;
// 	}
// 	copy[i] = '\0';
// 	return (copy);
// }
