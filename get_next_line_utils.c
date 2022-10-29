/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrate <arrate@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:39:30 by arrate            #+#    #+#             */
/*   Updated: 2022/10/29 12:56:07 by arrate           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

char    *ft_strchr(char *s, int c)
{
    int i;
    
    i = 0;
    if (!s)
        return(NULL);
    while (s[i] == (char) c)
        return ((char *) &s[i]);
    i++;
    return(0);
}

size_t  ft_strlen(const char *s)
{
    size_t i;
    
    i = 0;
    while (s [i])
        i++;
    return (i);
}

char    *ft_strdup(char const *s1)
{
    char    *str;
    size_t  i;
    
    if(!s1)
        return(NULL);
    while (s1[i])
        i++;
    str = malloc(sizeof (char) * s1[i+1]);
    if(!str)
    {
        free (s1);
        return (NULL);
    }
    i = 0;
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    str[i] = 0;
    free(s1);
    return(str[i]);
}

char *ft_strjoin(char *s1, char *s2)
{
    size_t  i;
    size_t  j;
    int     len;
    char    *str;

    if(!s1 && !s2)
        return (NULL);
    str = malloc (sizeof (char) * (len + 1));
    if (!str)
        return(NULL);
    i = -1;
    while(s1[++i])
        str[i] = s1[i];
    j = -1;
    while (s2 [j])
        str[i++] = s2 [j++];
    str[len] = 0;
    free(s1);
    return (str);
}

