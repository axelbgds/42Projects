/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 09:00:23 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/01 07:13:15 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_word_char(char c)
{
	return (
		(c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9')
	);
}

char	*ft_strcapitalize(char *str)
{
	char	*tmp;

	tmp = str;
	if (str[0] >= 'a' && str[0] <= 'z')
	{
		str[0] -= 'a' - 'A';
	}
	str++;
	while (str[0] != 0)
	{
		if (is_word_char(str[0]) && (is_word_char(str[-1]) == 0))
		{
			if (str[0] <= 'z' && str[0] >= 'a')
			{
				str[0] -= 'a' - 'A';
			}
		}
		else if (str[0] >= 'A' && str[0] <= 'Z')
		{
			str[0] += 'a' - 'A';
		}
		str++;
	}
	return (tmp);
}
