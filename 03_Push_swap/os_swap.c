/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   os_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perp.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:42:55 by abeaugra          #+#    #+#             */
/*   Updated: 2023/03/16 12:07:05 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_push_swap.h"

static void	swap(t_lst **lst)
{
	int	tmp;
	
	if (*lst && (*lst)->next)
	{
		tmp = (*lst)->data;
		(*lst)->data = (*lst)->next->data;
		(*lst)->next->data = tmp;
	}
}

void	sa(t_lst **lst_a, int flag)
{
	swap(lst_a);
	if (flag)
		ft_putendl_fd("sa", 1);
}

void	sb(t_lst **lst_b, int flag)
{
	swap(lst_b);
	if (flag)
		ft_putendl_fd("sb", 1);
}

void	ss(t_lst **lst_a, t_lst **lst_b, int flag)
{
	swap(lst_a);
	swap(lst_b);
	if (flag)
		ft_putendl_fd("ss", 1);
}
