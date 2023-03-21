#include "push_swap.h"

int	getpmin(t_list *stack)
{
	int	min;
	int	pos;
	int	l;

	l = 0;
	pos = 0;
	min = stack->num;
	while (stack)
	{
		if (stack->num < min)
		{
			pos = l;
			min = stack->num;
		}
		l++;
		stack = stack->next;
	}
	return (pos);
}
/*La fonction size_5 commence par appeler la fonction
getpmin pour déterminer la position de l'élément le plus
petit dans la pile stack_a ensuite elle boucle tant que la
taille de la pile stack_a est supérieure à trois elle commence
par vérifier si la pile stack_a est déjà triée en appelant la
fonction ft_cro si c'est le cas et que la pile stack_b est vide,
elle retourne sinon elle vérifie la position de l'élément
le plus petit dans la pile stack_a en utilisant la valeur de pmin
si pmin est supérieur à 2 elle appelle la fonction rra pour
faire une rotation vers le bas sur la pile stack_a si pmin est
inférieur ou égal à 2 elle appelle la fonction ra pour faire
une rotation vers le haut sur la pile stack_a si pmin est zéro 
elle appelle la fonction pb pour pousser l'élément supérieur
de la pile stack_a sur la pile stack_b enfin elle met à jour la valeur
de pmin en appelant la fonction getpmin après la boucle elle
appelle la fonction size_3 pour trier les trois éléments restants
dans la pile stack_a ensuite elle boucle sur la pile stack_b et utilise
la fonction pa pour pousser chaque élément sur la pile stack_a.*/
void	size_5(t_list **stack_a, t_list **stack_b)
{
	int	pmin;

	pmin = getpmin(*stack_a);
	while (ft_lstsize(*stack_a) > 3)
	{
		if (ft_cro(*stack_a) && !*stack_b)
			return ;
		if (pmin > 2 && pmin)
			rra(stack_a, 1);
		else if (pmin <= 2 && pmin)
			ra(stack_a, 1);
		else if (!pmin)
			pb(stack_a, stack_b, 1);
		pmin = getpmin(*stack_a);
	}
	size_3(stack_a);
	while (*stack_b)
		pa(stack_b, stack_a, 1);
}
