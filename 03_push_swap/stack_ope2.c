/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:45:48 by abeaugra          #+#    #+#             */
/*   Updated: 2023/02/27 12:45:48 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ra function rotates the stack a up (to the right) by moving the first element to the end of the stack. */
void    ra(t_stack **a)
{
    t_stack *tmp;

    if(!(*a) || !((*a)->next))
        return ;
    tmp = (*a)->next;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = *a;
    (*a) = (*a)->next;
    tmp->next->next = NULL;
}

/* rb rotates the stack b up (to the right) by moving the first element to the end of the stack. */
void    rb(t_stack **b)
{
    t_stack *tmp;

    if(!(*b) || !((*b)->next))
        return ;
    tmp = (*b)->next;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = *b;
    (*b) = (*b)->next;
    tmp->next->next = NULL;
}

/* rr function rotates both stacks a and b upwards (to the right). */
void    rr(t_stack **a, t_stack **b)
{
    ra(a);
    rb(b);
}

/* rra rotates the stack a downwards (to the left) by moving the last element to the beginning of the stack. */
void    rra(t_stack **a)
{
    t_stack *tmp;
    
    if(!(*a) || !((*a)->next))
        return ;
    tmp = *a;
    while(tmp->next->next)
        tmp = tmp->next;
    tmp->next->next = *a;
    *a = tmp->next;
    tmp->next = NULL;
}

/*  rrb rotates the stack b downwards (to the left) by moving the last element to the beginning of the stack. */
void    rrb(t_stack **b)
{
    t_stack *tmp;

    if(!(*b) || ((*b)->next))
        return ;
    tmp = *b;
    while (tmp->next->next)
        tmp = tmp->next;
    tmp->next->next = *b;
    *b = tmp->next;
    tmp->next = NULL;
}