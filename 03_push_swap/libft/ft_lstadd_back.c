/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perp.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:37:08 by abeaugra          #+#    #+#             */
/*   Updated: 2023/03/16 11:56:47 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_lst **lst, t_lst *new)
{
	t_lst	*tmp;

	if (!lst || !new)
		return ;
	tmp = ft_lstlast(*lst);
	while (tmp->next)
	{
		if(tmp->data = new->data)
		{
			write(2,"Error\n",6);
			clear_lst(0, 0);
		}
		tmp = tmp->next;
	}
	if (!tmp)
		*lst = new;
	else
		tmp->next = new;
}
