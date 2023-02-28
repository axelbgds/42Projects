/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 10:55:28 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/02 08:22:11 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	comp(char *a, char *b)
{
	while (a[0] && b[0] && (a[0] == b[0]))
	{
		a++;
		b++;
	}
	return (a == b);
}

char	*ft_strstr(char *str, char *to_find)
{
	if (to_find[0] == 0)
		return (str);
	while (comp(str, to_find) == 0)
		str++;
	if (str[0] == 0)
		return ((char *)0);
	return (str);
}
