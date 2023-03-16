/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   os_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perp.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:21:43 by abeaugra          #+#    #+#             */
/*   Updated: 2023/03/16 12:07:30 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_push_swap.h"

static void	rotate(t_lst **lst)
{
	t_lst *tmp;
	t_lst	*first;
	
	if(*lst && (*lst)->next)
	{
		tmp = *lst;
		first = *lst;
		*lst = (*lst)->next;
		ft_lstlast(first);
		tmp->next = first;
		first->next = NULL;
	}
}

void	ra(t_lst **lst_a, int flag)
{
	rotate(lst_a);
	if (flag)
		ft_putendl_fd("ra", 1);
}

void	rb(t_lst **lst_b, int flag)
{
	rotate(lst_b);
	if (flag)
		ft_putendl_fd("rb", 1);
}

void	rr(t_lst **lst_a, t_lst **lst_b, int flag)
{
	rotate(lst_a);
	rotate(lst_b);
	if (flag)
		ft_putendl_fd("rr", 1);
}
