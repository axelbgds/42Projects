/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perp.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:43:49 by abeaugra          #+#    #+#             */
/*   Updated: 2023/03/07 13:46:54 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* stack_new:
*	Creates a stack elements with the provided value.
*	Returns the newly created stack element.
*/
t_stack *stack_new(int value)
{
    t_stack *new;

    new = malloc(sizeof * new);
    if (!new)
        return (NULL);
    new->value = value;
    new->index = 0;
    new->pos = -1;
    new->target = -1;
    new->len_a = -1;
    new->len_b = -1;
    new->next = NULL;
    return (new);
}

/* get_stack_size:
*	Returns the number of elements in a stack.
*/
int get_stack_size(t_stack *stack)
{
    int size;
    
    size = 0;
    if (!stack)
        return (0);
    while (stack)
    {
        stack = stack->next;
        size++;
    }
    return (size);
}

/* get_stack_bottom:
*	Returns the last element of the stack.
*/
t_stack *get_stack_bottom(t_stack *stack)
{
    while (stack && stack->next != NULL)
        stack = stack->next;
    return (stack);
}

/* add_stack_bottom:
*	Adds an element to the bottom of a stack.
*/
void stack_add_bottom(t_stack **stack, t_stack *new)
{
    t_stack *tail;
    
    if (!new)
        return ;
    if (!*stack)
    {
        *stack = new;
        return ;
    }
    tail = get_stack_bottom(*stack);
    tail->next = new;
}

/* get_stack_before_bottom:
*	Returns the second to last element of the stack.
*/
t_stack *get_stack_before_bottom(t_stack *stack)
{
    while (stack && stack->next && stack->next->next != NULL)
        stack = stack->next;
    return (stack);
}