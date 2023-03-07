/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perp.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:07:32 by abeaugra          #+#    #+#             */
/*   Updated: 2023/03/07 15:36:52 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* is_correct_input:
*   Checks if the given arguments are all numbers, without duplicates.
*   Return: 1 if the arguments are valid, 0 if not.
*/
int is_correct_input(char **av)
{
    int i;
    
    i =0;
    if (is_sign(av[i]))
        i++;
    while (av[i] && av[i])
        i++;
    if (av[i])
        return (0);
    return (1);
}

int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

int is_sign(char c)
{
    return (c == '+'  || c == '-');
}

/* nbstr_cmp:
*   Compares two strings of digits to check if they are the same or not.
*   If one of the strings starts with a '+' sign, it is ignored and the rest
*   of the number string is checked.
*   This is so that +123 == 123 but -123 != 123.
*   Return: 0 if the strings match, another value if they do not.
*/
int nbstr_cmp(const char *s1, const char *s2)
{
    int i;
    int j;

    i = 0;
    j = i;
    if (s1[i] == '+')
    {
        if (s2[j] != '+')
            i++;
    }
    else
    {
        if (s2[j] == '+')
            j++;
    }
    while (s1[i] && s2[j] && s1[i] == s2[j])
    {
        i++;
        j++;
    }
    return ((unsigned char) s1[i] - (unsigned char)s2[j]);
}