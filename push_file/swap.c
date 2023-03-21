#include"push_swap.h"

void	swap(t_list **stack)
{
	int	tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->num;
	(*stack)->num = (*stack)->next->num;
	(*stack)->next->num = tmp;
}

void	sa(t_list **stack, int flag)
{
	swap(stack);
	if (flag)
		ft_putendl_fd("sa", 1);
}

void	sb(t_list **stack, int flag)
{
	swap(stack);
	if (flag)
		ft_putendl_fd("sb", 1);
}

void	ss(t_list **stack_a, t_list **stack_b, int flag)
{
	swap(stack_a);
	swap(stack_b);
	if (flag)
		ft_putendl_fd("ss", 1);
}
