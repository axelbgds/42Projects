/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 10:47:27 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/02 08:21:39 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*tmp;

	tmp = dest;
	while (dest[0])
		dest++;
	while (src[0] && nb)
	{
		dest[0] = src[0];
		src++;
		dest++;
		nb--;
	}
	dest[0] = 0;
	return (tmp);
}
