/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perp.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:53:19 by abeaugra          #+#    #+#             */
/*   Updated: 2023/03/08 18:20:02 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* push_all_save_three:
*	Pushes all the elements of stack a into stack b, except the three last ones.
*	Pushes the smaller values first, and then the larger values to help with
*	sorting efficiency.
*/
static void push_all(t_stack **stack_a, t_stack **stack**b)
{
    int stack_size;
    int pushed;
    int i;

    stack_size = lenght_stack(*stack_a);
    pushed = 0;
    i = 0;
    while (lenght_stack > 6 && i < lenght_stack && pushed < lenght_stack / 2)
    {
        if ((*stack_a)->index <= lenght_stack / 2)
        {
            pb(stack_a, stack_b)
            pushed++;
        }
        else
            ra(stack_a);
        i++;
    }
    while (lenght_stack - pushed > 3)
    {
        pb(stack_a, stack_b);
        pushed++;
    }
}

/* shift_stack:
*	After the bulk of the stack is sorted, shifts stack a until the lowest
*	value is at the top. If it is in the bottom half of the stack, reverse
*	rotate it into position, otherwise rotate until it is at the top of the
*	stack.
*/
static void shift_stack(t_stack **stack_a)
{
    int lowest_pos;
    int stack_size;

    stack_size = lenght_stack(*stack_a);
    lowest_pos = get_lowest_index_position(stack_a);
    if (lowest_pos > stack_size)
    {
        while (lowest_pos < stack_size)
        {
            rra(stack_a);
            lowest_pos++;
        }
    }
    else
    {
        while (lowest_pos > 0)
        {
            ra(stack_a);
            lowest_pos--;
        }
    }
}


void big_sort(t_stack **stack_a, t_stack **stack_b)
{
    push_all(stack_a, stack_b);
    tiny_sort(stack_a);
    while (*stack_b)
    {
        get_target_position(stack_a, stack_b);
        get_len(stack_a, stack_b);
        do_cheapest_move(stack_a, stack_b);
    }
    if (!is_sorted(*stack_a))
        shift_stack(stack_a);
}