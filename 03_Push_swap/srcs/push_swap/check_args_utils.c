/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 09:35:40 by abeaugra          #+#    #+#             */
/*   Updated: 2023/06/27 09:54:29 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

//chec is negative
int	sign(int c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

//check is digit
int	digit(int c)
{
	if ((c >= 48) && (c <= 57))
		return (1);
	return (0);
}

//check is space character
int	space(int c)
{
	if (c == ' ')
		return (1);
	return (0);
}


