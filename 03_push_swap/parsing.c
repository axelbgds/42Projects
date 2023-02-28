/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:49:33 by abeaugra          #+#    #+#             */
/*   Updated: 2023/02/27 12:43:32 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Checks if there are duplicate in the array */
int check_duplicate(int *array, int size)
{
    int i;
    int j;
    
    i =0;
    while(i <size)
    {
        j = i + 1;
        while(j < size)
        {
            if(array[i] == array[j])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

/* Return 1 if c is digit */
int ft_isdigit(int c)
{
    if(c >= '0' && c <= '9')
        return (1);
    return (0);
}

/* Return 1 if c is whitespace */
int ft_isspace(int c)
{
    if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v')
        return (1);
    return (0);
}

/* Return int value */
int ft_atoi(const char *str)
{
    long long   num;
    int         sign;
    
    num = 0;
    sign = 1;
    while (ft_isspace(*str))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while(ft_isdigit(*str))
    {
        num = (num * 10) + (*str - '0');
        if (num * sign > 2147483648 || num * sign < -2147483648)
            return (0);
        str++;
    }
    return ((int) (num * sign));
}

/* Check args */
int check_args(int ac, char **av, int *array, int size)
{
    int i;

    i =0;
    if (ac != size +1)
        return (0);
    while(i < size)
    {
        array[i] = ft_atoi(av[i +1]);
        if ( !array[i])
            return(0);
        i++;
    }
    if (check_duplicate(array, size))
        return (0);
    return (1);
}