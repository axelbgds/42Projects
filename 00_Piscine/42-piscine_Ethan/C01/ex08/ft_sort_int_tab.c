/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 08:41:45 by elorenze          #+#    #+#             */
/*   Updated: 2022/01/29 08:47:43 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	success;
	int	i;
	int	tmp;

	success = 0;
	while (success == 0)
	{
		success = 1;
		i = 0;
		while (i < (size - 1))
		{
			if (tab[i] > tab[i + 1])
			{
				success = 0;
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tab[i];
			}
			i++;
		}
	}
}
