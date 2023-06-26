/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perp.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 09:35:40 by abeaugra          #+#    #+#             */
/*   Updated: 2023/06/26 15:24:19 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Sorts and pushes stacks until only 3 elements remain.
void	sortb_3(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;

	while (ft_lstsize(*stack_a) > 3 && !check_sort(*stack_a))
	{
		tmp = *stack_a;
		i = rotate_ab(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == case_rarb(*stack_a, *stack_b, tmp->nbr))
				i = rarb(stack_a, stack_b, tmp->nbr, 'a');
			else if (i == case_rrarrb(*stack_a, *stack_b, tmp->nbr))
				i = rrarrb(stack_a, stack_b, tmp->nbr, 'a');
			else if (i == case_rarrb(*stack_a, *stack_b, tmp->nbr))
				i = rarrb(stack_a, stack_b, tmp->nbr, 'a');
			else if (i == case_rrarb(*stack_a, *stack_b, tmp->nbr))
				i = rrarb(stack_a, stack_b, tmp->nbr, 'a');
			else
				tmp = tmp->next;
		}
	}
}

// Pushes all elements from stack_a into stack_b one by 
// one until only three elements remain, ensuring 
// that stack_b is sorted.
t_stack	*sort_push_b(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) > 3 && !check_sort(*stack_a))
		pb(stack_a, &stack_b, 0);
	if (ft_lstsize(*stack_a) > 3 && !check_sort(*stack_a))
		pb(stack_a, &stack_b, 0);
	if (ft_lstsize(*stack_a) > 3 && !check_sort(*stack_a))
		sortb_3(stack_a, &stack_b);
	if (!check_sort(*stack_a))
		sort_3(stack_a);
	return (stack_b);
}

// Pushes elements from stack_b into stack_a until stack_b is empty.
t_stack	**sort_push_a(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;

	while (*stack_b)
	{
		tmp = *stack_b;
		i = rotate_ba(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == case_rarb_a(*stack_a, *stack_b, tmp->nbr))
				i = rarb(stack_a, stack_b, tmp->nbr, 'b');
			else if (i == case_rarrb_a(*stack_a, *stack_b, tmp->nbr))
				i = rarrb(stack_a, stack_b, tmp->nbr, 'b');
			else if (i == case_rrarrb_a(*stack_a, *stack_b, tmp->nbr))
				i = rrarrb(stack_a, stack_b, tmp->nbr, 'b');
			else if (i == case_rrarb_a(*stack_a, *stack_b, tmp->nbr))
				i = rrarb(stack_a, stack_b, tmp->nbr, 'b');
			else
				tmp = tmp->next;
		}
	}
	return (stack_a);
}

// Sorts stack_a if there are more than 2 elements, pushes
// the elements into stack_b to sort them, then pushes them
// back into stack_a. Finally, bring the smallest number
// to the top of stack_a.
void	sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) == 2)
		sa(stack_a, 0);
	else
	{
		stack_b = sort_push_b(stack_a);
		stack_a = sort_push_a(stack_a, &stack_b);
		i = find_index(*stack_a, ft_min(*stack_a));
		if (i < ft_lstsize(*stack_a) - i)
		{
			while ((*stack_a)->nbr != ft_min(*stack_a))
				ra(stack_a, 0);
		}
		else
		{
			while ((*stack_a)->nbr != ft_min(*stack_a))
				rra(stack_a, 0);
		}			
	}	
}
