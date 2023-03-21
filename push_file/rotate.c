#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_lstadd_back(stack, tmp);
}

void	ra(t_list **stack, int flag)
{
	rotate(stack);
	if (flag)
		ft_putendl_fd("ra", 1);
}

void	rb(t_list **stack, int flag)
{
	rotate(stack);
	if (flag)
		ft_putendl_fd("rb", 1);
}

void	rr(t_list **stack_a, t_list **stack_b, int flag)
{
	rotate(stack_a);
	rotate(stack_b);
	if (flag)
		ft_putendl_fd("rr", 1);
}
