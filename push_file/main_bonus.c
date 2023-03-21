#include"push_swap.h"

int	exec_func2(char *func, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(func, "sa"))
		return (sa(stack_a, 0), 1);
	else if (!ft_strncmp(func, "rra"))
		return (rra(stack_a, 0), 1);
	else if (!ft_strncmp(func, "sb"))
		return (sb(stack_b, 0), 1);
	else if (!ft_strncmp(func, "ss"))
		return (ss(stack_a, stack_b, 0), 1);
	else if (!ft_strncmp(func, "ra"))
		return (ra(stack_a, 0), 1);
	else if (!ft_strncmp(func, "rb"))
		return (rb(stack_b, 0), 1);
	return (0);
}

void	exec_func(char *func, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(func, "rr"))
		rr(stack_a, stack_b, 0);
	else if (!ft_strncmp(func, "rrb"))
		rrb(stack_b, 0);
	else if (!ft_strncmp(func, "rrr"))
		rrr(stack_a, stack_b, 0);
	else if (!ft_strncmp(func, "pa"))
		pa(stack_b, stack_a, 0);
	else if (!ft_strncmp(func, "pb"))
		pb(stack_a, stack_b, 0);
	else if (!exec_func2(func, stack_a, stack_b))
	{
		write(2, "Error\n", 6);
		lb(0, 0);
	}
}

void	read_func(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		exec_func(line, stack_a, stack_b);
		free(line);
		line = get_next_line(0);
	}
	free(line);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac > 1)
	{
		stack_a = pr_arg(av + 1);
		read_func(&stack_a, &stack_b);
		if (ft_cro(stack_a) && !stack_b)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	lb(0, 10);
}
