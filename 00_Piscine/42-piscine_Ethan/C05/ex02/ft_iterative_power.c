/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 06:57:11 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/04 08:41:16 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	out;
	int	i;	

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	out = nb;
	i = 0;
	while (i < (power - 1))
	{
		out *= nb;
		i++;
	}
	return (out);
}
