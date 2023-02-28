/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 07:53:49 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/03 14:44:44 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putnbr_base(int nbr, char *base);

int	main(void)
{
	struct {
		int nb;
		char *base;
	} tests[] = {
		{-2147483648, "0123456789"},
		{-2147483648, "0123456789ABCDEF"}
	};
	unsigned long i = 0;

	while (i < (sizeof(tests)/sizeof(tests[0])))
	{
		printf("%d, %s: ", tests[i].nb, tests[i].base);
		fflush(stdout);
		ft_putnbr_base(tests[i].nb, tests[i].base);
		fputc('\n', stdout);
		i++;
	}
}
