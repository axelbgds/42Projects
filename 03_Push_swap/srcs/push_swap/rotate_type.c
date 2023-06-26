/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perp.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 09:35:40 by abeaugra          #+#    #+#             */
/*   Updated: 2023/06/26 15:23:42 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Calculates and decides the best rotations
// to sort the stack when moving from B to A.
int	rotate_ba(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp;

	tmp = b;
	i = case_rrarrb_a(a, b, b->nbr);
	while (tmp)
	{
		if (i > case_rarb_a(a, b, tmp->nbr))
			i = case_rarb_a(a, b, tmp->nbr);
		if (i > case_rrarrb_a(a, b, tmp->nbr))
			i = case_rrarrb_a(a, b, tmp->nbr);
		if (i > case_rarrb_a(a, b, tmp->nbr))
			i = case_rarrb_a(a, b, tmp->nbr);
		if (i > case_rrarb_a(a, b, tmp->nbr))
			i = case_rrarb_a(a, b, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}

// Calculates and decides the best rotations
// to sort the stack when moving from A to B.
int	rotate_ab(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp;

	tmp = a;
	i = case_rrarrb(a, b, a->nbr);
	while (tmp)
	{
		if (i > case_rarb(a, b, tmp->nbr))
			i = case_rarb(a, b, tmp->nbr);
		if (i > case_rrarrb(a, b, tmp->nbr))
			i = case_rrarrb(a, b, tmp->nbr);
		if (i > case_rarrb(a, b, tmp->nbr))
			i = case_rarrb(a, b, tmp->nbr);
		if (i > case_rrarb(a, b, tmp->nbr))
			i = case_rrarb(a, b, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}
