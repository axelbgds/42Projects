/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   os_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:42:55 by abeaugra          #+#    #+#             */
/*   Updated: 2023/03/14 13:21:23 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap(t_stack **stack)
{
	int	tmp;
	
	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->data;
		(*stack)->data = (*stack)->next->data;
		(*stack)->next->data = tmp;
	}
}

void	sa(t_stack **stack_a)
{
	swap(stack_a);
	ft_putstr("sa\n");
}

void	sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_putstr("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr("ss\n");
}
