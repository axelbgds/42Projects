/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   os_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:27:03 by abeaugra          #+#    #+#             */
/*   Updated: 2023/03/09 10:27:05 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//revoir fonction en tabl
static void	push(t_list **stack)
{
	t_list	*tmp;

	if(*stack && (*stack)->next)
	{
		tmp = (*stack)->content;
		(*stack)->content = (*stack)->next->content;
		(*stack)->next->content = tmp;
		ft_putstr("sa\n");
	}
}

/* 
*	Swaps the top 2 elements of stack a.
*	Prints "sa" to the standard output.
*/

void	sa(t_stack **stack_a)
{
	swap(*stack_a);
	ft_putstr("sa\n");
}

void	sb(t_list **stack_b)
{
	swap(*stack_b);
	ft_putstr("sb\n");
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr("ss\n");
}