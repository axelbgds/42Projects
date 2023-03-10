/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:08:25 by abeaugra          #+#    #+#             */
/*   Updated: 2023/03/10 14:08:29 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* verifie le signe convertit */
int	char_to_int(char *str)
{
	int	ret;
	int	i;
	
	i =-1;
	if ((str[0] == '-' || str[0] == '+') && !str[1])
		return(write(2,"Error\n",6),clear_stack(0,0),0);
	ret = ft_atoi(str);
	return(ret);
}

/* convertit each elmt en int et ajoute a la fin de la liste*/
t_stack	*char_to_list(char **av)
{
	t_list	*head;
	int	i;
	
	head = NULL;
	i = -1;
	while(av[++i]
		ft_lstadd_back(&head, ft_lstnew(char_to_int(av[i]),0));
	retur (head);
}

void	check_space(char **av)
{
	int	i;
	int	j;
	
	i = -1;
	while(av[++i])
	{
		j = 0;
		while (av[i][j] && av[i][j] == 32)
			j++;
		if (av[i][j] == 0)
		{
			write(2,"Error\n",2);
			clear_stack(0,0);
		}
	}
}

/* nettoie la * en supprimant les 32 -> stack  */
t_stack	put_arg(char **av)
{
	char	*str;
	int	i
	t_stack	*list;

	str = NULL;
	check_space(av);
	i = -1;
	while(av[i++])
		str = ft_strjoin(av[i]);
	list = char_to_end(ft_split(str, ' '));
	return(list);	
}

/* verifie si * est croiss*/
bool	ft_croissant(t_stack *stack)
{
	if(stack)
	{
		while (stack->next)
		{
			if (stack->num < stack->next->num)
				stack = stack->next;
			else
				return(false);
		}
	}
}
