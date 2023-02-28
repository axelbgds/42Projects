/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 08:20:21 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/07 06:51:01 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (
		nb <= 1
		|| ((nb % 2) == 0 && nb != 2)
	)
		return (0);
	i = 3;
	while (i < (nb / 2))
	{
		if ((nb % i) == 0)
			return (0);
		i++;
	}
	return (1);
}