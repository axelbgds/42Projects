/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perp.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 09:35:40 by abeaugra          #+#    #+#             */
/*   Updated: 2023/06/26 15:43:01 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Function to parse the args from the " "
// send them to add_args function to add into list.
// With ft_split we split numbers from spaces.
t_stack	*parse_args_quote(char **argv)
{
	t_stack	*stack_a;
	char	**tmp;
	int		i;
	int		j;

	stack_a = NULL;
	i = 0;
	tmp = ft_split(argv[1], 32);
	add_args(tmp, &stack_a);
	freestr(tmp);
	free(tmp);
	return (stack_a);
}

// This function performs three checks: less than 2
// entries, exactly 2 entries as a string in 
// quotation marks, more than 2 entries that are enumerated.
t_stack	*parse(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;
	int		j;

	i = 1;
	stack_a = NULL;
	if (argc < 2)
		ft_error();
	else if (argc == 2)
		stack_a = parse_args_quote(argv);
	else
	{
		add_args(argv, &stack_a);
	}
	return (stack_a);
}
