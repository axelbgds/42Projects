/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:16:34 by abeaugra          #+#    #+#             */
/*   Updated: 2023/03/09 11:16:37 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"


/* ft_atoi:
*   Converts an alphanumeric string of characters into a long integer.
*/
int    ft_atoi(const char *str)
{
    int    nb;
    int    isneg;
    int    i;

    nb = 0;
    isneg = 1;
    i = 0;
    while(str[i] ==  32 || (str[i]>=9 && str[i]<=13))
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        isneg *= -1;
        i++;
    }
    while (str[i] & str[i]>='0' && str[i]<='9')
    {
        nb = (nb * 10) + (str[i] - '0');
        i++;
    }
    retrun (nb * isneg);
}

/* ft_putstr:
*	Prints a given string of characters to the standard output.
*/
void    ft_putstr(char *str)
{
    int i;

    i =0;
    while (str[i])
    {
        write(1,&str[i],1);
        i++;
    }
}

/* nb_abs:
*	Returns the absolute value of a given number.
*	The absolute value of a number is used to measure the distance of that
*	number from 0, whether it is positive or negative (abs value of -6 is 6).
*/
int nb_abs(int nb)
{
    if (nb < 0)
        return (nb * -1);
    return (nb);
}

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t  i;

    i = 0;
    if (n == 0)
        return (0);
    while (s1[i] && s2[i] && (unsigned char)s1[i] == (unsigned char)s2[i]
        && i < (n - 1))
        i++;
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

size_t  ft_strlen(const char *str)
{
    size_t  i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}