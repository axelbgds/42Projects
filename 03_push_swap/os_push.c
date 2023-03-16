/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   os_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perp.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:29:58 by abeaugra          #+#    #+#             */
/*   Updated: 2023/03/16 12:09:04 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_push_swap.h"

static void	push(t_lst **src, t_lst **dest)
{
	t_lst	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = NULL;
	ft_lstadd_front(dest, tmp);
}

void	pa(t_lst **src, t_lst **dest, int flag)
{
	push(src, dest);
	if (flag)
		ft_putendl_fd("pa", 1);
}

void	pb(t_lst **src, t_lst **dest, int flag)
{
	push(src, dest);
	if (flag)
		ft_putendl_fd("pa", 1);
}

