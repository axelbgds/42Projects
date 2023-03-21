#include "push_swap.h"

int	get_max(t_list *stack)
{
	int	max;

	max = stack->num;
	while (stack)
	{
		if (stack->num > max)
			max = stack->num;
		stack = stack->next;
	}
	return (max);
}
/*la fonction "sort_3" est une fonction de tri qui
triera une pile de 3 éléments. Si la pile contient
exactement 3 éléments, elle commence par appeler la
fonction "get_max" pour trouver le plus grand élément
de la pile. Ensuite, elle utilise les fonctions "ra"
(rotation vers le haut), "rra" (rotation vers le bas)
et "sa" (échange de deux premiers éléments de la pile)
pour trier la pile en fonction de l'ordre de ses éléments.*/

void	size_3(t_list **s)
{
	int	max;

	max = get_max(*s);
	if (ft_lstsize(*s) == 3)
	{
		if ((*s)->num == max)
			ra(s, 1);
		else if ((*s)->next->num == max)
			rra(s, 1);
	}
	if ((*s)->num > (*s)->next->num)
		sa(s, 1);
}
/*La logique de tri fonctionne comme suit :
Si le nombre le plus élevé est en haut de la pile, il est poussé
vers le bas en effectuant une rotation vers le haut de la pile.
Sinon, si le nombre le plus élevé est en bas de la pile, il est
poussé vers le haut en effectuant une rotation vers le bas de la pile.
Enfin, si les deux premiers éléments de la pile sont dans le mauvais
ordre, ils sont échangés en utilisant la fonction "sa".*/