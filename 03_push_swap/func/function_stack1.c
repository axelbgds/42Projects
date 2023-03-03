/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_list_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:40:46 by abeaugra          #+#    #+#             */
/*   Updated: 2023/02/27 15:40:47 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	new_stack(void)
{
	return NULL;
}

/******************************************************************************/

Bool	is_empty(t_stack st)
{
	if (st == NULL)
		return true;
	return false;
}

/******************************************************************************/

void	init_stack(t_stack *st, int size)
{
	if(!*st || !size)
		return NULL;
}

/******************************************************************************/

/* Print stack */
void 	print_stack(t_stack st)
{
	if (is_empty(st))
	{
		printf("Rien a afficher la liste est vide\n");
		return ;
	}
	while(!is_empty(st))
	{
		printf("[%d]\n", st->data);
		st = st->next;
	}
}

/******************************************************************************/

/* Clean memory */
t_stack	clear_stack(t_stack st)
{
	t_stack	*elmt;
	if (is_empty(st))
		return (new_stack);
	elmt = st->next;
	free(st);
	return clear_stack(elmt);
}
