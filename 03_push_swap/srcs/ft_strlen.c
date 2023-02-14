/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:10:19 by abeaugra          #+#    #+#             */
/*   Updated: 2022/03/25 16:27:29 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*  The strlen() function computes the length 
*   of the string s. The strnlen()function 
*   attempts to compute the length of s, 
*   but never scans beyond the first maxlen bytes of s
*/

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
/*
int	main(void)
{
    char *s;
    s = "Hello";
    printf("%d\n", ft_strlen(s));
    return (0);
}*/