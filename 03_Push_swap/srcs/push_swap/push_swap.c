/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 09:35:40 by abeaugra          #+#    #+#             */
/*   Updated: 2023/06/27 10:05:30 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = process(argc, argv);
	if (check_args(argv))
	{	
		stack_free(&a);
		ft_error();
	}
	if (!a || check_dup(a))
	{
		stack_free(&a);
		ft_error();
	}
	if (!check_sort(a))
		sort(&a);
	stack_free(&a);
	return (0);
}
