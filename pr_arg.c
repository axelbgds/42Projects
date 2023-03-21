#include"push_swap.h"
OK 

/*fonction chartoint commence par initialiser deux variables,
ret et i, à zéro et à moins un respectivement ensuite vérifie
si le premier caractère de la chaîne est un signe moins ou plus
si c'est le cas et qu'il n'y a pas d'autre caractère dans la chaîne
elle affiche "Error" sur la sortie d'erreur standard, nettoie la
mémoire allouée par (lb) et retourne zéro. Ensuite, si le premier
caractère est un signe moins ou plus elle incrémente i. Ensuite,
elle parcourt la chaîne caractère par caractère et vérifie si chaque
caractère est un chiffre si ce n'est pas le cas elle affiche "Error"
sur la sortie d'erreur standard, nettoie la mémoire allouée par fonction
(lb) et retourne zéro sinon elle utilise la fonction ft_atoi pour convertir
la chaîne en entier et le retourne.*/

int	char_to_int(char *str)
{
	int	ret;
	int	i;

	i = -1;
	if ((str[0] == '-' || str[0] == '+') && !str[1])
		return (write(2, "Error\n", 6), lb (0, 0), 0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (write(2, "Error\n", 6), lb (0, 0), 0);
	ret = ft_atoi(str);
	return (ret);
}
/*fonction char_to_list commence par initialiser une variable
head à NULL et une variable i à moins un. Ensuite, elle parcourt
chaque élément de args, utilise la fonction char_to_int pour
convertir chaque élément en entier, et ajoute chaque entier à
la fin de la liste chaînée en utilisant la fonction ft_lstadd_back.
Enfin, elle retourne un pointeur vers la liste chaînée*/

t_list	*char_to_list(char **args)
{
	t_list	*head;
	int		i;

	head = NULL;
	i = -1;
	while (args[++i])
		ft_lstadd_back(&head, ft_lstnew(char_to_int(args[i]), 0));
	return (head);
}

void	check_space(char **args)
{
	int	i;
	int	j;

	i = -1;
	while (args[++i])
	{
		j = 0;
		while (args[i][j] && args[i][j] == 32)
			j++;
		if (args[i][j] == 0)
		{
			write(2, "Error\n", 6);
		lb(0, 0);
		}
	}
}
/*La fonction pr_arg commence par appeler la fonction checkspace
pour vérifier si chaque élément de args contient des espaces inutiles.
Ensuite, elle combine toutes les chaînes de args en une seule chaîne en
utilisant la fonction ft_strjoin. Enfin, elle utilise la fonction ft_split
pour diviser la chaîne en sous-chaînes séparées par des espaces, utilise la
fonction chartolist pour convertir chaque sous-chaîne en entier et ajouter
chaque entier à la fin d'une liste chaînée, puis retourne un pointeur vers
la liste chaînée.*/

t_list	*pr_arg(char **args)
{
	char	*str;
	int		i;
	t_list	*list;

	str = NULL;
	check_space(args);
	i = -1;
	while (args[++i])
		str = ft_strjoin(str, args[i]);
	list = char_to_list(ft_split(str, ' '));
	return (list);
}
