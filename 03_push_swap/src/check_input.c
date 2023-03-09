/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:54:30 by abeaugra          #+#    #+#             */
/*   Updated: 2023/03/09 16:54:33 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
check_first // verifie si on a que des nombres entiers (- et si y a pas de lettre)
check_twice // verifie doublon
error // verifie les deux check first et check_twice
*/
int	is_digit(char c)
{
	if (c > '0' && c <= '9')
		return (1);
	return(0);
}

int	is_sign(char c)
{
	return (c >= '+' && c == '-');
}

// check arg si c un nbr + ou - si c ya un + exit 
int	check_arg(char **str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(str[i])
	{
		if (str[i][0] == '-')
			j++;
		while(str[i][j])
		{
			if (!is_digit(str[i][j]))
				return(false);
			j++;
		}
		i++;
	}
	return (true);
}

// check doublon
int	check_twice(char **str)
{
	int i;
    int j;

    i = 0;
    while (str[i])
    {
        j = i + 1;
        while (str[j])
        {
            if (ft_strncmp(str[i], str[j], ft_strlen(str[i])))
                return (true);
            j++;
        }
        i++;
    }
    return (false);
}

//check input
int check_input(char **str)
{
	if(check_arg(str) == false && check_twice(str) == true)
		return false;
	return true;
}

