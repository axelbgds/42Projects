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

char	*ft_strdup(const char *s1)
{
	char	*result;
	int		index;

	index = 0;
	while (s1[index])
		index++;
	result = malloc(sizeof(*result) * (index + 1));
	if (!result)
		return (NULL);
	index = 0;
	while (s1[index])
	{
		result[index] = s1[index];
		index++;
	}
	result[index] = '\0';
	return (result);
}
