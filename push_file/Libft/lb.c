#include"libft.h"
/*La fonction utilise une variable statique head qui
pointe vers la tête d'une liste chaînée de nœuds,
chacun stockant un pointeur vers une adresse allouée avec malloc.
**Si param est 1, cela signifie que la fonction doit
allouer de la mémoire. La fonction commence donc par
appeler malloc pour allouer size octets de mémoire.
**Si l'allocation réussit, la fonction alloue également
un nouveau nœud pour stocker l'adresse allouée. Si
l'allocation du nœud réussit également, la fonction
ajoute ce nœud à la liste chaînée en utilisant la
fonction ft_lstadd_front, puis renvoie l'adresse allouée.
**Si l'allocation de mémoire ou de nœud échoue, la
fonction appelle la fonction ft_lstclear pour
libérer tous les nœuds précédemment alloués
avec malloc, puis appelle exit(1) pour quitter
le programme avec un code d'erreur.
**Si param est 0, cela signifie que la fonction
doit libérer toute la mémoire allouée précédemment.
La fonction appelle donc ft_lstclear pour libérer
tous les nœuds précédemment alloués avec malloc,
puis appelle exit(1) pour quitter le programme avec un code d'erreur.
**Enfin, si param n'est ni 0 ni 1, la fonction appelle
ft_lstclear pour libérer tous les nœuds précédemment
alloués avec malloc, puis appelle exit(0) pour quitter
le programme avec un code de succès.*/
void	*lb(size_t size, int param)
{
	static t_list	*head;
	void			*address;
	t_list			*node;

	if (param == 1)
	{
		address = malloc(size);
		if (!address)
			return (ft_lstclear(&head, free), exit(1), NULL);
		node = malloc(sizeof(t_list));
		if (!node)
			return (ft_lstclear(&head, free), exit(1), NULL);
		node->address = address;
		node->next = NULL;
		ft_lstadd_front(&head, node);
		return (address);
	}
	if (!param)
		return (ft_lstclear(&head, free), exit(1), NULL);
	return (ft_lstclear(&head, free), exit(0), NULL);
}
