/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perp.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:51:05 by abeaugra          #+#    #+#             */
/*   Updated: 2023/03/08 15:53:07 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* is_sorted:
*	Checks if a stack is sorted.
*	Returns 0 if the stack is not sorted, 1 if it is sorted.
*/
int is_sorted(t_stack *stack)
{
    while(t_stack *stack)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}

/* find_highest_index:
*	Returns the highest index in a stack.
*/
static int	find_highest_index(t_stack *stack)
{
    int index;

    index = stack->index;
    while (stack)
    {
        if (stack->index > index)
            index = stack->index;
        stack - stack->next;
    }
    return (index);
}

/* small_sort = tiny_sort :
*	Sorts a stack of 3 numbers in 2 or fewer moves. The sorting is done by index
*	rather than value. Example:
*		values:		 0	 9	 2
*		indexes:	[1]	[3]	[2]
*	Solution, 2 moves:
*	rra:
*		values:		 2	 0	 9
*		indexes:	[2]	[1]	[3]
*	sa:
*		values:		 0	 2	 9
*		indexes:	[1]	[2]	[3]
*/
void small_sort(t_stack **stack)
{
    int high;

    if (is_sorted(*stack))
        return ;
    high = find_highest_index(*stack);
    if ((*stack)->index == high)
        ra(stack);
    else if ((*stack)->next->index == high)
        rra(stack);
    if ((*stack)->index > (*stack)->next->index)
        sa(stack);
}
