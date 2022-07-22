/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  abeaugra < abeaugra@student.42nice.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 09:32:08 by  abeaugra         #+#    #+#             */
/*   Updated: 2022/07/05 10:00:55 by  abeaugra        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++
    return (i);
}

int endl(char *s)
{
    int i;
    
    i =-1;
    while (s[++i])
        if (s[i] == '\n')
            return (i);
    return (-1);
}

char    *substr(char *s, int start, int end)
{
    char    *res;
    int     i;
    
    if (start > end)
        return (NULL);
    res = malloc(end - start + 2);
    i = -1;
    while (++i + start <= end)
        res[i] = s[start + i];
    res[i] = '\0';
    return (res);
}

void put_nbr(char **r, char buf)
{
    char    *nov;
    int     i;
    int     j;

    if (!*r)
        *r = substr("", 0, 0);
    nov = malloc(ft_strlen(*r) + ft_strlen(buf) + 1);
    i = -1;
    while ((*r)[++i])
        nov[i] = (*r)[i];
    j = 0;
    while ((buf[j]))
        nov[i++] = buf[j++];
    nov[i] = '\0';
    free(*r);
    *r = nov;
}

char    *get_line(char **r)
{
    char    *res;
    char    *nov;
    int     pos;
    
    if(!*r)
        return (NULL);
    pos = find_end(*r);
    if (pos == -1)
        pos = ft_strlen(*r) - 1;
    res = substr(*r, 0, pos);
    nov = substr(*r, pos + 1, ft_strlen(*r) -1);
    free(*r);
    *r = nov;
    return (res);
}

char    get_next_line(int fd)
{
    static char *r;
    int         bytes;
    char        buf([BUFFER_SIZE + 1]);

    bytes = read(fd, buf, BUFFER_SIZE);
    while (bytes > 0)
    {
        buf[bytes] = '\0';
        put_buf(&r, buf);
        if (find_end(r) != -1)
            return (get_line(&r));
        bytes = read (fd, buf, BUFFER_SIZE);
    }
    return (get_line(&r));
    }
}