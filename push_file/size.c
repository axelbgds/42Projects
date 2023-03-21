#include"push_swap.h"
/*La fonction implémente une recherche de sous-séquence
croissante. Elle parcourt tous les éléments de la pile,
en comparant chaque élément à node, et si l'élément actuel
a une valeur inférieure à celle de node et une sous-séquence
croissante plus grande ou égale, elle met à jour la valeur de
la sous-séquence croissante pour node. Si la sous-séquence
croissante de node est supérieure à celle de l'élément
actuel (tmp), elle met à jour maxlis pour pointer sur
node. Sinon, elle met à jour maxlis pour pointer sur
tmp. Si la fin de la liste est atteinte, la fonction
repart du début de la pile (stack). La fonction liste
est appelée dans la fonction get_lis.*/

void	liste(t_list *tmp, t_list *node, t_list **maxlis, t_list *stack)
{
	while (tmp != node)
	{
		if (tmp->num < node->num && tmp->lis >= node->lis)
		{
			node->address = tmp;
			node->lis++;
		}
		if (node->lis > tmp->lis)
			*maxlis = node;
		else
			*maxlis = tmp;
		tmp = tmp->next;
		if (!tmp)
			tmp = stack;
	}
}
/*La fonction implémente une recherche de sous-séquence croissante
pour chaque élément de la pile à partir de start.
Elle appelle la fonction liste pour chaque élément de
la pile, met à jour la sous-séquence croissante pour chaque
élément et met à jour maxlis pour pointer sur l'élément ayant
la plus grande sous-séquence croissante.
La fonction get_lis est appelée dans la fonction get_list.*/

void	get_lis(t_list *stack, t_list *start, t_list **maxlis)
{
	t_list	*tmp;
	t_list	*node;
	int		size;

	size = ft_lstsize(stack);
	tmp = stack;
	node = start;
	while (size-- >= 0)
	{
		tmp = start;
		liste(tmp, node, maxlis, stack);
		node = node->next;
		if (!node)
			node = stack;
	}
}
/*La fonction implémente une recherche de sous-séquence croissante
pour chaque élément de la pile. Elle appelle la fonction get_lis pour
chaque élément de la pile met à jour la valeur de numlis pour chaque élément
ayant une sous-séquence croissante croissante, et marque les éléments ayant
une sous-séquence croissante en les stockant dans keep.
La fonction get_list est appelée dans la fonction size.*/

void	get_list(t_list *stack, int *numlis)
{
	int		size;
	t_list	*tmp;
	t_list	*maxlis;

	size = -1;
	tmp = stack;
	while (tmp)
	{
		tmp->keep = 0;
		tmp->lis = 0;
		tmp = tmp->next;
	}
	tmp = stack;
	while (++size < getpmin(stack))
		tmp = tmp->next;
	get_lis(stack, tmp, &maxlis);
	while (maxlis)
	{
		(*numlis)++;
		maxlis->keep = 1;
		maxlis = maxlis->address;
	}
}
/*La fonction implémente l'algorithme Push Swap pour
trier la pile A.elle déplace les éléments du stack_a
vers le stack_b jusqu'à ce qu'il ne reste que les éléments
les plus petits dans stack_a. Ensuite, elle trie les éléments
dans stack_b en les déplaçant à nouveau vers stack_a en ordre croissant.
Une fois que get_list a déterminé la taille de la plus longue sous-séquence
croissante dans stack_a, la fonction size commence à déplacer les éléments
de stack_a vers stack_b. Elle déplace tous les éléments qui ne font pas partie
de la plus longue sous-séquence croissante, en les empilant sur stack_b Elle
conserve les éléments de la plus longue sous-séquence croissante sur stack_a
en les faisant simplement tourner.
Une fois que tous les éléments ont été déplacés de stack_a vers stack_b 
la fonction sorting est appelée pour trier les éléments dans stack_b en
ordre croissant, en les déplaçant à nouveau vers stack_a.
Enfin, la fonction size place les éléments les plus petits
de stack_a en haut de la pile en les faisant tourner vers
le haut ou vers le bas, en fonction de leur position par
rapport au milieu de la pile.*/

void	size(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	lstsize;

	size = 0;
	get_list(*stack_a, &size);
	lstsize = ft_lstsize(*stack_a) - size;
	while (lstsize)
	{
		if (!((*stack_a)->keep == 1))
		{
			pb(stack_a, stack_b, 1);
			lstsize--;
		}
		else
			ra(stack_a, 1);
	}
	while (ft_lstsize(*stack_b))
		sorting(stack_a, stack_b);
	if (getpmin(*stack_a) <= ft_lstsize(*stack_a) / 2)
		while (getpmin(*stack_a))
			ra(stack_a, 1);
	if (getpmin(*stack_a) > ft_lstsize(*stack_a) / 2)
		while (getpmin(*stack_a))
			rra(stack_a, 1);
}
