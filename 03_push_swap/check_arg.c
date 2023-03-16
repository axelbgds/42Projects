/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perp.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:08:25 by abeaugra          #+#    #+#             */
/*   Updated: 2023/03/16 12:24:40 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_push_swap.h"

/* Verifie le signe convertit */
int	char_to_int(char *str)
{
	int	ret;
	int	i;
	
	i =-1;
	if ((str[0] == '-' || str[0] == '+') && !str[1])
		return(write(2,"Error\n",6),clear_lst(0,0),0);
	ret = ft_atoi(str);
	return(ret);
}

/* Convertit each elmt en int et ajoute a la fin de la liste*/
t_lst	*char_to_list(char **av)
{
	t_lst	*head;
	int	i;
	
	head = NULL;
	i = -1;
	while(av[++i])
		ft_lstadd_back(&head, ft_lstnew(char_to_int(av[i]), 0)); // pb avec proto lstnew >?
	return (head);
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
			clear_lst(0,0);
		}
	}
}

/* Nettoie la * en supprimant les 32 -> lst  */
t_lst	*put_arg(char **av)
{
	char	*str;
	int		i;
	t_lst	*list;

	str = NULL;
	check_space(av);
	i = -1;
	while(av[i++])
		str = ft_strjoin(str, av[i]);
	list = char_to_end(ft_split(str, ' '));
	return (list);
}

/* Verifie si * est croiss*/
bool	ft_croissant(t_lst *lst)
{
	if(lst)
	{
		while (lst->next)
		{
			if (lst->data < lst->next->data)
				lst = lst->next;
			else
				return(false);
		}
	}
}
