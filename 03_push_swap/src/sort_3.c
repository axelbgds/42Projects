/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:10:03 by abeaugra          #+#    #+#             */
/*   Updated: 2023/03/10 14:20:45 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* recupere le max de la stack */
int	get_max(t_stack *stack)
{
	int	max;

	max = stack->data;
	while(stack)
	{
		if(stack->data > max)
			max = stack->data;
		stack = stack->next;
	}
	return(max);
}

/* sort 3 elmt si 3 && max a la debut = ra || max fin = rra || si deux elmt sont pas croissant swap  */
void	sort_3(t_stack **s)
{
	int max;
	
	max = get_max(*s);
	if (ft_lstsize(*s) == 3)
	{
		if ((*s)->data == max)
			ra(s, 1);
		else ((*s)->next->data == max)
			rra(s, 1); 
	}
	if ((*s)->data > (*s)->next->data)
		sa(s, 1);
}
