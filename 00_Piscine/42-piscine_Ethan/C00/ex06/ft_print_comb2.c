/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 09:40:33 by elorenze          #+#    #+#             */
/*   Updated: 2022/01/28 06:43:18 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_nbr2(int n)
{
	char tmp[2];

	tmp[0] = '0' + (n / 10);
	tmp[1] = '0' + (n % 10);
	write(1, tmp, 2);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < 100)
	{
		j = i + 1;
		while (j < 100)
		{
			if (j != 1)
			{
				write(1, ", ", 2);
			}
			print_nbr2(i);
			write(1, " ", 1);
			print_nbr2(j);
			j++;
		}
		i++;
	}
}
