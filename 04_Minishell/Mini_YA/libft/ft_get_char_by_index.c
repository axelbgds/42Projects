/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_char_by_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:10:13 by abeaugra          #+#    #+#             */
/*   Updated: 2023/06/29 12:12:26 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_get_char_by_index(char *str, char c)
{
	char	*d;

	d = ft_strchr(str, c);
	if (!d)
		return (-1);
	return ((size_t)(d - str));
}