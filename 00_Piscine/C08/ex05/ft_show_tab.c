/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 06:47:47 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/11 07:25:12 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_stock_str.h"

void	ft_putnbr(int nb)
{
	char	buff;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if ((nb / 10) > 0)
		ft_putnbr(nb / 10);
	buff = '0' + (nb % 10);
	write(1, &buff, 1);
}

/* 2 parce que si je compile avec l'exo 04 elle exisre deja. */
int	ft_strlen2(char *str)
{
	char	*start;

	start = str;
	while (str[0])
	{
		str++;
	}
	return (str - start);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		write(1, par[i].str, par[i].size);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		write(1, par[i].copy, ft_strlen2(par[i].copy));
		write(1, "\n", 1);
		i++;
	}
}
