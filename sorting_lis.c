#include "push_swap.h"

/*g_index prend une pile de nombres et ajoute un attribut
keep à chaque élément de la pile en fonction de sa position. 
Les éléments qui sont plus petits que la médiane reçoivent une
valeur positive qui représente le nombre de positions qu'ils
doivent se déplacer vers le haut pour atteindre leur position
finale, tandis que les éléments plus grands reçoivent une valeur
négative qui représente le nombre de positions qu'ils doivent 
se déplacer vers le bas.*/

// list_sorta

void	g_index(t_list *stack)
{
	int	i;
	int	j;
	int	size;

	size = ft_lstsize(stack);
	j = 0;
	i = -1;
	while (++i <= size / 2 && stack)
	{
		stack->keep = i;
		stack = stack->next;
	}
	j = size / 2;
	if (size % 2 == 0)
		j--;
	while (stack)
	{
		stack->keep = -j;
		j--;
		stack = stack->next;
	}
}
/* getmin trouve l'élément le plus petit dans une pile.*/

t_list	*getmin(t_list *sa)
{
	t_list	*min;

	min = sa;
	while (sa)
	{
		if (sa->num < min->num)
			min = sa;
		sa = sa->next;
	}
	return (min);
}
/*g_moves prend deux piles de nombres et ajoute un attribut
lis à chaque élément de la pile B. L'attribut lis représente
le nombre de mouvements nécessaires pour déplacer l'élément de
la pile B à sa position finale dans la pile A en fonction
des valeurs de keep des éléments dans les deux piles.*/

void	g_moves(t_list *stack_a, t_list *stack_b)
{	
	t_list	*tmp;
	int		pob;
	int		poa;

	g_index(stack_a);
	g_index(stack_b);
	tmp = stack_b;
	while (tmp)
	{
		tmp->address = node_c(stack_a, tmp);
		poa = tmp->address->keep;
		pob = tmp->keep;
		if (poa < 0 && pob < 0)
			tmp->lis = ((poa < pob) * poa + (pob * !(poa < pob))) * -1;
		else if (poa >= 0 && pob >= 0)
			tmp->lis = (poa >= pob) * poa + (pob * !(poa >= pob));
		else if (poa >= 0 && pob < 0)
			tmp->lis = (pob * -1) + poa;
		else if (poa < 0 && pob >= 0)
			tmp->lis = (poa * -1) + pob;
		tmp = tmp->next;
	}
}
/*push_b prend deux piles de nombres et un élément de la pile B
et détermine quelle opération push_swap doit exécuter pour déplacer
cet élément dans la pile A en fonction des valeurs keep de l'élément
et de l'élément au sommet de la pile A.*/

void	push_b(t_list **stack_a, t_list **stack_b, t_list *node)
{
	if (node->address->keep >= 0 && node->keep >= 0)
		push_1(stack_a, stack_b, node);
	else if (node->address->keep < 0 && node->keep < 0)
		push_2(stack_a, stack_b, node);
	else if (node->address->keep >= 0 && node->keep < 0)
		push_3(stack_a, stack_b, node);
	else if (node->address->keep < 0 && node->keep >= 0)
		push_4(stack_a, stack_b, node);
}
/*sorting prend deux piles de nombres et effectue une boucle jusqu'à
ce que la pile B soit vide. Pendant chaque itération
elle utilise g_moves pour calculer lis pour chaque élément de la pile B
puis utilise push_b pour déplacer l'élément avec la valeur lis minimale
de la pile B vers la pile A.*/

void	sorting(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*node;
	int		moves;

	g_moves(*stack_a, *stack_b);
	tmp = *stack_b;
	moves = tmp->lis;
	node = tmp;
	while (tmp)
	{
		if (moves > tmp->lis)
		{
			moves = tmp->lis;
			node = tmp;
		}
		tmp = tmp->next;
	}
	push_b(stack_a, stack_b, node);
}
