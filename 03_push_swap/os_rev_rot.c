/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   os_rev_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perp.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:06:35 by abeaugra          #+#    #+#             */
/*   Updated: 2023/03/16 12:08:39 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_push_swap.h"

static void	rev_rot(t_lst **lst)
{
	t_lst	*last;
	
	if(*lst && (*lst)->next)
	{
		last = ft_lstlast(*lst);
		ft_lstadd_front(*lst, last);
		last = NULL;
	}
}
	
void	rra(t_lst **lst_a, int flag)
{
	rrotate(lst_a);
	if (flag)
		ft_putendl_fd("rra", 1);
}

void	rrb(t_lst **lst_b, int flag)
{
	rrotate(lst_b);
	if (flag)
		ft_putendl_fd("rrb", 1);
}

void	rrrt_list(t_lst **lst_a, t_lst **lst_b, int flag)
{
	rrotate(lst_a);
	rrotate(lst_b);
	if (flag)
		ft_putendl_fd("rrr", 1);
}
