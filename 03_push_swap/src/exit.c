


#include "push_swap.h"

void    free_stack(t_list **stack)
{
    t_list *tmp;

    if (!stack || !(*stack))
        return ;
    while (*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
    *stack = NULL;
}

// exit