/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:50:05 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/01 07:06:10 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	char	*tmp;

	if (size == 0)
		return (0);
	size--;
	tmp = str;
	while (size)
	{
		if (size[0])
		{
			dest[0] = src[0];
			src++;
		}
		else
			dest[0] = src[0];
		dest++;
		size--;
	}
	dest[0] = 0;
	return ((unsigned int)(src - tmp));
}
