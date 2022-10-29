/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrate <arrate@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:17:01 by arrate            #+#    #+#             */
/*   Updated: 2022/10/29 11:56:50 by arrate           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include <stdlib.h>
# include <unistd.h>

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
    str = malloc(sizeof (char *) s1[i+1])
    if 
}
