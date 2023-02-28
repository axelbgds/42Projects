/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 07:53:41 by elorenze          #+#    #+#             */
/*   Updated: 2022/01/27 15:33:48 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* tous les chiffres sont plus grand que son/ses voinsin(s) de gauche. */
/* sinon y'a un doublon, ou il la combinaison a deja ete affichee */
int	is_new(int n)
{
	return (
		(((n / 10) % 10) > (n / 100))
		&& (((n / 10) % 10) < (n % 10))
		&& (n % 10) > (n / 100)
	);
}

void	print_nbr(int n) {
	char tmp[3];

	tmp[0] = '0' + (n / 100);
	tmp[1] = '0' + ((n / 10) % 10);
	tmp[2] = '0' + (n % 10);
	write(1, tmp, 3);
}

void	ft_print_comb(void)
{
	int	i;

	i = 12;
	while (i < 990)
	{
		if (is_new(i))
		{
			if (i != 12)
			{
				write(1, ", ", 2);
			}
			print_nbr(i);
		}
		i++;
	}
}
