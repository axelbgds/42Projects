/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ope1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:45:54 by abeaugra          #+#    #+#             */
/*   Updated: 2023/02/27 12:45:54 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Swap the first two elements of stack A */
void	sa(t_stack **a)
{
	if (!*a || !(*a)->next)
		return ;
	int tmp = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = tmp;
}

/* Swap the first two elements of stack B */
void	sb(t_stack **b)
{
	if (!*b || !(*b)->next)
		return ;
	int tmp = (*b)->data;
	(*b)->data = (*b)->next->data;
	(*b)->next->data = tmp;
}

/* sa and sb at the same time */
void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}

/* Pop the first element of stack B and push it to stack A */
void	pa(t_stack **a, t_stack **b)
{
	if (!*b)
		return ;
	t_stack *tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
}

/* Pop the first element of stack A and push it to stack B */
void	pb(t_stack **a, t_stack **b)
{
	if (!*a)
		return ;
	t_stack *tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
}