/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:36:27 by abeaugra          #+#    #+#             */
/*   Updated: 2022/03/30 16:24:58 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	The strchr() function locates the first occurrence of c 
*	(converted to a char) in the string pointed to by s.
*	The terminating null character is considered to be part 
*	of the string; therefore if c is `\0', the functions 
*	locate the terminating `\0'.*/

char	*ft_strchr(const char *s, int c)
{
	int	len;
	int	i;

	i = 0;
	len = (int)ft_strlen(s) + 1;
	while (i < len)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

/* #include <stdio.h>
int main () 
{
	//check(ft_strchr(s, 0) == s + strlen(s)); showLeaks();
	const char str[] = "Diego de. la .Vega";
	const char ch = '.';
	char *ret;
	ret = ft_strchr(str, ch);
	printf("String after |%c| is - |%s|\n", ch, ret);
	return(0);
}*/
