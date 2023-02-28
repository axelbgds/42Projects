/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 10:35:56 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/01 14:50:09 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (s1[0] && s2[0] && (s1[0] == s2[0]))
	{
		s1++;
		s2++;
	}
	return ((int)((int)s1[0]) - ((int)s2[0]));
}