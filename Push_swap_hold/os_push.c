/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   os_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:26:39 by abeaugra          #+#    #+#             */
/*   Updated: 2023/03/09 10:26:46 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* push:
*	Pushes the top element of src stack to the top of dest stack.
*/
//revoir fonction en tabl
static void	push(t_list **src, t_list **dest)
{
	t_list	*tmp;

	if (*src)
	{
		tmp = *src;
		*src = (*src)->next;
		temp->next = *dest;
		*dest = tmp;
	}
}

/*
*	Pushes the top element of stack b to the top of stack a.
*	Prints "pa" to the standard output.
*/
void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr("pa\n");
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr("pb\n");
}
