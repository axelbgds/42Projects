/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:50:45 by abeaugra          #+#    #+#             */
/*   Updated: 2022/03/25 14:06:43 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	The strrchr() function is identical to strchr(), except 
*	it locates the last occurrence of c.*/

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = (int)ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == (char)c)
			return ((char *)(s + len));
			len --;
	}
	return (NULL);
}
/*
int main () 
{
   const char str[] = "Diego de. la. Vega";
   const char ch = '.';
   char *ret;
   ret = ft_strrchr(str, ch);
   printf("String after |%c| is - |%s|\n", ch, ret);
   return(0);
}*/