/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perp.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:28:38 by abeaugra          #+#    #+#             */
/*   Updated: 2023/06/19 21:30:46 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_ope(t_stacks *stack, char *opt)
{
	if (ft_strcmp(opt, "sa\n"))
		ft_sa(stack, 1);
	else if (ft_strcmp(opt, "sb\n"))
		ft_sb(stack, 1);
	else if (ft_strcmp(opt, "ss\n"))
		ft_ss(stack, 1);
	else if (ft_strcmp(opt, "ra\n"))
		ft_ra(stack, 1);
	else if (ft_strcmp(opt, "rb\n"))
		ft_rb(stack, 1);
	else if (ft_strcmp(opt, "rr\n"))
		ft_rr(stack, 1);
	else if (ft_strcmp(opt, "rra\n"))
		ft_rra(stack, 1);
	else if (ft_strcmp(opt, "rrb\n"))
		ft_rrb(stack, 1);
	else if (ft_strcmp(opt, "rrr\n"))
		ft_rrr(stack, 1);
	else if (ft_strcmp(opt, "pa\n"))
		ft_pa(stack, 1);
	else if (ft_strcmp(opt, "pb\n"))
		ft_pb(stack, 1);
}

int
	ft_check_ope(char *opt, t_stacks *stack)
{
	if (ft_strcmp(opt, "sa\n") || ft_strcmp(opt, "sb\n")
		|| ft_strcmp(opt, "ss\n") || ft_strcmp(opt, "ra\n")
		|| ft_strcmp(opt, "rb\n") || ft_strcmp(opt, "rra\n")
		|| ft_strcmp(opt, "rrb\n") || ft_strcmp(opt, "rrr\n")
		|| ft_strcmp(opt, "pa\n") || ft_strcmp(opt, "pb\n")
		|| ft_strcmp(opt, "rr\n"))
		return (1);
	else if (!opt
		&& ft_check_sorted(stack->a, stack->size_a, 0))
	{		
		ft_printf("\033[0;32mOK\n");
		return (0);
	}
	else
	{
		ft_printf("Error\n");
		return (0);
	}
}

void
	ft_checker_next(t_stacks *stack)
{
	char		*opt;

	while (1)
	{
		opt = get_next_line(0);
		if (ft_strcmp(opt, "\n"))
		{
			if (ft_check_sorted(stack->a, stack->size_a, 0)
				&& stack->size_b == 0)
				ft_printf("\033[0;32mOK\n");
			else
				ft_printf("\033[0;31mK0\n");
			free(stack->a);
			free(stack->b);
			exit (1);
		}
		if (!ft_check_ope(opt, stack))
		{
			free(stack->a);
			free(stack->b);
			return ;
		}
		ft_ope(stack, opt);
	}
}

void
	ft_checker(char *av[])
{
	t_stacks		stack;
	register int	size;
	register int	index;

	index = -1;
	size = ft_ps_strlen(av);
	stack.a = malloc(size * sizeof(int));
	if (!stack.a)
		return ;
	stack.size_a = size;
	stack.b = malloc(size * sizeof(int));
	if (!stack.b)
	{
		free(stack.a);
		return ;
	}
	stack.size_b = 0;
	while (++index < size)
		stack.a[index] = ft_ps_atoi(av[index], stack.a);
	ft_check_repeat(stack.a, size);
	ft_checker_next(&stack);
}

int
	main(int ac, char *av[])
{
	if (ac > 1)
	{
		av++;
		if (ac == 2)
			av = ft_split(*av, ' ');
		ft_checker(av);
		return (0);
	}
	return (0);
}
