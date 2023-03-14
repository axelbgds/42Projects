/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   os_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:21:43 by abeaugra          #+#    #+#             */
/*   Updated: 2023/03/14 14:32:40 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack *tmp;
	t_stack	*first;
	
	if(*stack && (*stack)->next)
	{
		tmp = *stak;
		first = *stack;
		*stack = (*stack)->next;
		ft_lstlast(first);
		tmp->next = first;
		first->next = NULL;
	}
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	putstr("ra\n");
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	putstr("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	putstr("rr\n");
}
