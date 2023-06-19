/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perp.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:28:38 by abeaugra          #+#    #+#             */
/*   Updated: 2023/06/19 21:31:24 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_sort_tmp(int *tmp_stack, int size)
{
	register int	index;
	register int	jndex;
	register int	temp;

	index = 0;
	while (index < size)
	{
		jndex = index + 1;
		while (jndex < size)
		{
			if (tmp_stack[index] > tmp_stack[jndex])
			{
				temp = tmp_stack[index];
				tmp_stack[index] = tmp_stack[jndex];
				tmp_stack[jndex] = temp;
			}
			jndex++;
		}
		index++;
	}
}

int
	ft_push(t_stacks *stack, int len, int operation)
{
	if (operation == 0)
		ft_pb(stack, 0);
	else
		ft_pa(stack, 0);
	len--;
	return (len);
}

void
	ft_sort_three_a(t_stacks *s)
{
	if (s->a[0] > s->a[1] && s->a[0] < s->a[2] && s->a[1] < s->a[2])
		ft_sa(s, 0);
	if (s->a[0] > s->a[1] && s->a[0] > s->a[2] && s->a[1] > s->a[2])
	{
		ft_sa(s, 0);
		ft_rra(s, 0);
	}
	if (s->a[0] > s->a[1] && s->a[0] > s->a[2] && s->a[1] < s->a[2])
		ft_ra(s, 0);
	if (s->a[0] < s->a[1] && s->a[0] < s->a[2] && s->a[1] > s->a[2])
	{
		ft_sa(s, 0);
		ft_ra(s, 0);
	}
	if (s->a[0] < s->a[1] && s->a[0] > s->a[2] && s->a[1] > s->a[2])
		ft_rra(s, 0);
}

int
	ft_sort(t_stacks *stack, int size)
{
	if (ft_check_sorted(stack->a, stack->size_a, 0) == 0)
	{
		if (size == 2)
			ft_sa(stack, 0);
		else if (size == 3)
			ft_sort_three_a(stack);
		else
			ft_quicksort_a(stack, size, 0);
	}
	return (0);
}
