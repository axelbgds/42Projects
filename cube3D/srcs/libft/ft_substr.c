/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:42:33 by alsaez            #+#    #+#             */
/*   Updated: 2023/02/07 14:12:55 by alsaez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = start;
	j = 0;
	if (!s)
		return (NULL);
	if (i > (ft_strlen(s) + 1))
		return (ft_strdup(""));
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	while (i < ft_strlen(s) && j < len)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
