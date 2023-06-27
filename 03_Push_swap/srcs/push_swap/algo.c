/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 09:35:40 by abeaugra          #+#    #+#             */
/*   Updated: 2023/06/27 11:05:03 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// 1. checks < 2.
// 2. checks = 2.
// 3. checks > 2.
int	atoi_push(const char *str, t_stack *a)
{
	int				mod;
	long long int	i;

	i = 0;
	mod = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
	{
		mod = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error();
		i = i * 10 + (*str - 48);
		str++;
	}
	if ((mod * i) > 2147483647 || (mod * i) < -2147483648)
	{	
		stack_free(&a);
		ft_error();
	}
	return (mod * i);
}

// This function sorts stacks of numbers enclosed in
// quotation marks into distinct integers.
t_stack	*sub_process(char **argv)
{
	t_stack	*a;
	char	**tmp;
	int		i;
	int		j;

	a = NULL;
	i = 0;
	tmp = ft_split(argv[1], 32);
	while (tmp[i])
	{
		j = atoi_push(tmp[i], a);
		ft_add_back(&a, ft_new_stack(j));
		i++;
	}
	freestr(tmp);
	free(tmp);
	return (a);
}

// either fewer than 2 entries, or exactly 2
// entries in the form of a string enclosed
// in quotation marks, or more than 2
// entries that are listed.
t_stack	*process(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		j;

	i = 1;
	a = NULL;
	if (argc < 2)
		ft_error();
	if (argc == 2)
		a = sub_process(argv);
	else
	{
		while (i < argc)
		{
			j = atoi_push(argv[i], a);
			ft_add_back(&a, ft_new_stack(j));
			i++;
		}
	}
	return (a);
}
