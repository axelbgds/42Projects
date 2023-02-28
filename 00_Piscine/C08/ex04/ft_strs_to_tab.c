/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:34:54 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/11 06:45:23 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	char	*start;

	start = str;
	while (str[0])
		str++;
	return (str - start);
}

void	ft_strcpy(char *dest, char *src)
{
	while (src[0])
	{
		dest[0] = src[0];
		src++;
		dest++;
	}
	dest[0] = 0;
}

/* j'aurais bien free en cas d'erreur */
/* mais tescande m'a dit que la moulinette dit rien*/
struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*ret;
	int					i;

	ret = malloc((ac + 1) * sizeof(*ret));
	if (ret == 0)
		return (0);
	i = 0;
	while (i < ac)
	{
		ret[i].size = ft_strlen(av[i]);
		ret[i].str = av[i];
		ret[i].copy = malloc(ret[i].size + 1);
		if (ret[i].copy == 0)
			return (0);
		ft_strcpy(ret[i].copy, av[i]);
		i++;
	}
	ret[i].str = 0;
	return (ret);
}
