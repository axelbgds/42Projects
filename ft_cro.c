#include "push_swap.h"

bool	ft_cro(t_list *stack)
{
	if (stack)
	{
		while (stack->next)
		{
			if (stack->num < stack->next->num)
				stack = stack->next;
			else
				return (false);
		}
	}
	return (true);
}
