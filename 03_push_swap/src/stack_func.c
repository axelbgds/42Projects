/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:16:27 by abeaugra          #+#    #+#             */
/*   Updated: 2023/03/09 11:16:28 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
init
new
size
add_last
last_stack
free
*/

t_list *new_stack(int size)
{
	t_list *new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->array = malloc(sizeof size);
	if (!new->array)
		return (NULL);
	new->size = size;
	return (new);
}

/* Check our value if there in INT_MIN and INT_MAX */
void	init_stack(int ac, char **av)
{
	int 	i;
	int 	arg;
	t_list	*res;

	i = 0;
	while(av[i])
	{
		arg = atoi(av[i])
		if (arg <= INT_MIN && arg >= INT_MAX)
			exit_error(1);
		if (i == 0)
			res = new_stack(arg);
		res->array[i] = arg;
		i++;
	}
	return(arg);
}

// int size_stack(t_list *stack)
// {

// }

// t_list *last_stack(t_list *stack)
// {

// }

// void add_last_stack(t_list **stack, t_list *new)
/* free_stack:
*	Frees each element in a given stack and sets the stack pointer to NULL.
*/

