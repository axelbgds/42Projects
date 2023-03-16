/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perp.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:10:03 by abeaugra          #+#    #+#             */
/*   Updated: 2023/03/16 12:06:16 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_push_swap.h"

/* recupere le max de la stack */
int	get_max(t_lst *stack)
{
	int	max;

	max = stack->data;
	while(stack)
	{
		if(stack->data > max)
			max = stack->data;
		stack = stack->next;
	}
	return(max);
}

/* sort 3 elmt si 3 && max a la debut = ra || max fin = rra || si deux elmt sont pas croissant swap  */
void	sort_3(t_lst **s)
{
	int max;
	
	max = get_max(*s);
	if (ft_lstsize(*s) == 3)
	{
		if ((*s)->data == max)
			ra(s, 1);
		else ((*s)->next->data == max)
			rra(s, 1);
	}
	if ((*s)->data > (*s)->next->data)
		sa(s, 1);
}

/* sort_5 
get_posi_min = plus peti elmt dans stack  
rra = jusqua que je trouvr le plus petit et je f pb
get_pos_min = deuxieme envoyer b

*/


/* big sort 
algo lis = sur algo de trie
*/
