/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perp.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:33:58 by abeaugra          #+#    #+#             */
/*   Updated: 2023/03/08 19:42:05 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

/* arg_is_number
* checks if the arg is a numb +1 1 and -1 are all valide numbers
* return 1 if the arg is number 0 if not 
*/

int  arg_is_number(char *av)
{
    int i;

    i = 0;
    if (is_sign(av[i]) && av[i + 1])
        i++;
    while (av[i] && is_digit(av[i]))
        i++;
    if (av[i] && !is_digit(av[i]))
        return (0);
    return (1);
}

/* twice == have_duplicate
* checks if the arg list has diplicate numbers
* return 1 if a duplicate is foune 0 if there are none
*/

int  twice(char **av)
{
    int i;
    int j;

    i = -1;
    while (av[i])
    {
        j = 1;
        while (av[j])
        {
            if (j != i && nbstr_cmp(av[i], av[j]) == 0)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

/* arg_is_zero
* checks the arg is a 0 to avoid 0 +0 duplicates and 0 0000 +00
* return 1 if the arg is a zero 0 if it contains anything else 
* than a zero
*/
int  arg_zero(char *av)
{
    int i;

    i = 0;
    if (is_sign(av[i]))
        i++;
    while (av[i] && av[i] == '0')
        i++;
    if (av[i])
        return (0);
    return (1);
}

/* is_correct 
* checks if the given arg are all numbers, woithous duplicates
* return 1 if the arg are valid 0 if not
*/

int is_correct(char **av)
{
    int i;
    int nb_zero;

    nb_zero = 0;
    i = -1;
    while (av[i])
    {
        if(!arg_is_number(av[i]))
            return (0);
        nb_zero += arg_zero(av[i]);
        i++;
    }
    if (nb_zero > 1)
        return (0);
    if (twice(av))
        return (0);
    return (1);
}
