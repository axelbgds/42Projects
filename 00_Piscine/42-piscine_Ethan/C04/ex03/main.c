/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 07:26:43 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/03 07:34:39 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str);

int main(void)
{
	char *tmp;
	size_t buffsize;

	tmp = NULL;
	buffsize = 0;
	while (1)
	{
		fputs("ft_user> ", stdout);
		getline(&tmp, &buffsize, stdin);
		printf("ft_atoi> %d\n", ft_atoi(tmp));
	}
}
