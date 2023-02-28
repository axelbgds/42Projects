/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 07:38:28 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/03 14:33:38 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);

char	*ft_strchr(char *s, char c)
{
	while (s[0] && s[0] != c)
		s++;
	if (s[0] == c)
		return (s);
	else
		return ((char *)0);
}

int	validate_base(char *base)
{
	while (
		base[0]
		&& base[0] != '-'
		&& base[0] != '+'
	)
	{
		if (ft_strchr(base + 1, base[0]))
			return (0);
		base++;
	}
	return (base[0] == 0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_size;
	long	a;

	a = nbr;
	base_size = ft_strchr(base, 0) - base;
	if (base_size <= 1 || validate_base(base) == 0)
		return ;
	if (a < 0)
		write(1, "-", 1);
	if (a < 0)
		a *= -1;
	if ((a / base_size) > 0)
		ft_putnbr_base(a / base_size, base);
	write(1, &base[a % base_size], 1);
}
