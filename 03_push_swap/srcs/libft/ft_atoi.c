************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 09:30:54 by abeaugra          #+#    #+#             */
/*   Updated: 2023/02/20 15:18:25 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	The atoi() function converts the initial portion of the string 
*	pointed to by str to int representation.*/

int	ft_atoi(const char *str)
{
	int	number;
	int	i;
	int	is_neg;

	is_neg = 1;
	number = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			is_neg = -1;
	while (str[i] >= '0' && str[i] <= '9')
		number = number * 10 + str[i++] - 48;
	return (number * is_neg);
}
/*
int main () {
 	printf("====ft_atoi====\n");
	printf("%d\n%d\n%d\n%d\n%d\n%d\n",
		ft_atoi("-283"), ft_atoi("  -+--283"), ft_atoi("283!20"), 
			ft_atoi("283a30"), ft_atoi("a30"), ft_atoi("!@#"));
	
	printf("====atoi====\n");
	printf("%d\n%d\n%d\n%d\n%d\n%d\n",
		atoi("-283"), atoi("  -+--283"), atoi("283!20"),
	      atoi("283a30"), atoi("a30"), atoi("!@#"));
   
   return(0);
}*/
