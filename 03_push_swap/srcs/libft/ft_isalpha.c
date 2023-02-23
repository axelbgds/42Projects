/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:07:30 by abeaugra          #+#    #+#             */
/*   Updated: 2023/02/20 15:15:22 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_isalpha() function tests for any character for which isupper(3) or
** islower(3) is true.  The value of the argument must be representable as an
** unsigned char or the value of EOF.
*/

int	ft_isalpha(int c)
{
	return (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')));
}
/*
int main()
{
    printf("%d\n", ft_isalpha('w'));
    printf("%d\n", isalpha('1'));
    return 0;
}
*/
