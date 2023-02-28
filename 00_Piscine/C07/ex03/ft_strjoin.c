/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 09:18:11 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/10 10:21:49 by elorenze         ###   ########.fr       */
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

int	get_size(int size, char **strs, char *sep)
{
	int	i;
	int	s;

	i = 0;
	s = 0;
	while (i < size)
	{
		s += ft_strlen(strs[i]);
		i++;
	}
	return (s + (ft_strlen(sep) * (size - 1)));
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ret;
	char	*ptr;
	int		i;

	i = -1;
	if (size == 0)
	{
		ret = malloc(1);
		if (ret)
			ret[0] = 0;
		return (ret);
	}
	ret = malloc(get_size(size, strs, sep) + 1);
	if (ret == 0)
		return (0);
	ptr = ret;
	while (++i < size)
	{
		ft_strcpy(ptr, strs[i]);
		ptr += ft_strlen(strs[i]);
		if (i < (size - 1))
			ft_strcpy(ptr, sep);
		ptr += ft_strlen(sep);
	}
	return (ret);
}
/*
int main(int argc, char *argv[])
{
	printf("chaine = %s", ft_strjoin(argc, argv, "!!"));
}*/
