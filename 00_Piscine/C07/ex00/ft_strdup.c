/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 06:58:42 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/08 07:07:01 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	char	*start;

	start = str;
	while (str[0])
		str++;
	return (str - start);
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*rtn;

	rtn = dest;
	while (src[0])
	{
		dest[0] = src[0];
		dest++;
		src++;
	}
	dest[0] = 0;
	return (rtn);
}

char	*ft_strdup(char *src)
{
	char	*ret;

	if (src == 0)
		return (0);
	ret = malloc(ft_strlen(src) + 1);
	if (ret == 0)
		return (0);
	return (ft_strcpy(ret, src));
}
