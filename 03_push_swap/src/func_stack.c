/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perp.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:43:49 by abeaugra          #+#    #+#             */
/*   Updated: 2023/03/08 19:29:05 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* new_stack = stack_new:
*	Creates a stack elements with the provided value.
*	Returns the newly created stack element.
*/
t_stack *new_stack(int value)
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

/* lenght_stack = stack_size
*	Returns the number of elements in a stack.
*/
int length_stack(t_stack *stack)
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

/* last_stack = get_stack_bottom:
*	Returns the last element of the stack.
*/
t_stack *last_stack(t_stack *stack)
{
    while (stack && stack->next != NULL)
        stack = stack->next;
    return (stack);
}

/* add_last_stack = add_stack_bottom:
*	Adds an element to the bottom of a stack.
*/
void add_last_stack(t_stack **stack, t_stack *new)
{
    t_stack *tail;
    
    if (!new)
        return ;
    if (!*stack)
    {
        *stack = new;
        return ;
    }
    tail = last_stack(*stack);
    tail->next = new;
}

/* get_twice_last_stack = get_stack_before_bottom:
*	Returns the second to last element of the stack.
*/
t_stack *get_twice_last_stack(t_stack *stack)
{
    while (stack && stack->next && stack->next->next != NULL)
        stack = stack->next;
    return (stack);
}