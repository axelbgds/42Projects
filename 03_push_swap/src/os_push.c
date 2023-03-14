/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   os_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:29:58 by abeaugra          #+#    #+#             */
/*   Updated: 2023/03/14 14:19:43 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push(t_stack *src, t_stack *dest)
{
	t_stack	*tmp;
	
	if(*src)
	{
		tmp = *src;
		*src = (*src)->next;
		tmp->next = *dest;
		*dest = tmp;
	}
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr("pa\n");
}

void	pb(t_stack **stack_b, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr("pb\n");
}

