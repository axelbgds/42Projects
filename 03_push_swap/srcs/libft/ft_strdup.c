/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:44:29 by abeaugra          #+#    #+#             */
/*   Updated: 2022/03/30 17:23:50 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	The strdup() function allocates sufficient memory for a copy of the
*	string s1, does the copy, and returns a pointer to it.  The pointer may
*	subsequently be used as an argument to the function free(3).*/

char	*ft_strdup(const char *s)
{
	char	*d;
	int		i;

	i = ft_strlen(s);
	d = malloc((i + 1) * sizeof(char));
	i = -1;
	if (d)
	{
		while (s[++i])
			d[i] = s[i];
		d[i] = 0;
	}
	return (d);
}
/*
int main()
{
    char *p1 = "Biloute";
    char *p2;
    p2 = ft_strdup(p1);
 
    printf("Duplicated string is : %s", p2);
    return (0);
}*/
