/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perp.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:55:12 by abeaugra          #+#    #+#             */
/*   Updated: 2023/03/16 11:55:32 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_push_swap.h"

int main(int ac, char **av)
{
	t_lst *lst_a;
	t_lst *lst_b;
	if(ac > 1)
	{
		lst_a = NULL;
		lst_b = NULL;
		lst_a = put_arg(av+1);
		if (!(ft_croissant(lst_a)))
		{
			if(lstsize(lst_a) <= 3)
				sort_3(lst_a);
			else if(lstsize(lst_a) <= 5)
				sort_5(lst_a, lst_b);
			else
				sort(lst_a, lst_b);
		}
	}
	clear_lst(0,2);
}
