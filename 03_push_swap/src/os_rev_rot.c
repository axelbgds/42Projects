/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   os_rev_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:06:35 by abeaugra          #+#    #+#             */
/*   Updated: 2023/03/14 15:48:52 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rev_rot(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;
	
	if(*stack && (*stack)->next)
	{
		last = ft_lstlast(stack);
		tmp = *stack;
		ft_lstadd_front(stack, last);
				
	}
}
	
void	rra(t_stack **stack_a)
{
	rev_rot(stack_a);
	putstr("rra\n");	
}

void	rrb(t_stack **stack_b)
{
	rev_rot(stack_b);
	putstr("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rot(stack_a);
	rev_rot(stack_b);
	putstr("rrr\n");
}
