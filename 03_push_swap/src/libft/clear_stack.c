/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:23:31 by abeaugra          #+#    #+#             */
/*   Updated: 2023/03/10 12:44:17 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*clear_stack(size_t size, int param)
{
	static t_stack	*head;
	void		*adress;
	t_stack		*node;
	if (param == 1)
	{	
		adress = malloc(size);
		if(!adress)
			return(lstclear(&head, free), exit(1), NULL);
		node = malloc(sizeof(t_stack));
		if (!node)
			return(lstclear(&head, free), exit(1), NULL);
		node->adress = adress;
		node->next = NULL;
		ft_lstadd_front(&head, node);
		return (adress);
	}
	if (!param)
		return (ft_lstclear(&head, free), exit(1), NULL);
	return (ft_lstcleat(&head, free), exit(0), NULL);
}
