/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:49:26 by abeaugra          #+#    #+#             */
/*   Updated: 2023/02/27 15:39:52 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack A;
	t_stack B;

	int i = 1;
	if (ac == 2)
		return 0;
	init_stack(&A, ac - 1);
	init_stack(&B, ac - 1);
	while (i < ac)
	{
		if (!is_valid_number (av[i]))
		{
			ft_putstr_fd("Error\n",2);
			return 1;
		}
		if (is_duplicate_number(A, ft_atoi(av[i])))
		{
			ft_putstr_fd("Error\n",2)
			return 1;
		}
		push_stack(&A, ft_atoi(av[i]));
		i++;
	}
	if (A_is_sorted(&A))
	{
		if (A->data <= 2)
			sort_vsm_stack(&A, &B);
		if (A->data <= 3)
			sort_small_stack(&A, &B);
		if (A->data <= 5)
			sort_middle_stack(&A, &B);
		else if
			sort_big_stack(&A, &B);
		return 0;
	}
	clear_stack(&A);
	clear_stack(&B);
	return 0;
}
