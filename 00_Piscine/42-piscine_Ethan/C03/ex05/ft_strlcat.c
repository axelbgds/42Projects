/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 11:05:23 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/02 11:44:44 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	get_length(char *a, char *b)
{
	unsigned int	tmp;

	tmp = 0;
	while (a)
	{
		a++;
		tmp++;
	}
	while (b)
	{
		b++;
		tmp++;
	}
	return (tmp);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	length;

	length = get_length(dest, src);
	if (size == 0)
		return (length);
	size--;
	while (dest[0] && size)
	{
		dest++;
		size--;
	}
	if (size == 0)
	{
		dest[0] = 0;
		return (length);
	}
	while (src[0] && size)
	{
		dest[0] = src[0];
		size--;
		src++;
	}
	dest[0] = 0;
	return (length);
}
