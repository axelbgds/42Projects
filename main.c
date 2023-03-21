#include "push_swap.h"
/*fonction principale du programme commence par vérifier
s'il y a plus d'un argument si tel est le cas elle
initialise deux piles de t_list à NULL: stack_a et stack_b
elle appelle pr_arg en passant av + 1 comme argument, qui
traite les arguments et les stocke dans stack_a.

Ensuite elle vérifie si la liste stack_a est déjà
croissant. Si c'est le cas, elle ne fait rien et
sort de la fonction sinon, elle vérifie la taille
de stack_a en utilisant la fonction ft_lstsize si
la taille est de 3 éléments ou moins elle appelle
la fonction size_3 pour trier stack_a. Si la taille
est entre 4 et 5 éléments inclus elle appelle la
fonction size_5 pour trier stack_a en utilisant
stack_b si la taille est supérieure à 5 éléments,
elle appelle la fonction size pour trier stack_a
en utilisant stack_b.

Finalement, elle appelle la fonction lb avec les
arguments 0 et 2 pour libérer la mémoire allouée
pour les listes et pour quitter le programme.*/


// OK

int	main(int ac, char **av)
{
	t_list	*stack_b;
	t_list	*stack_a;

	if (ac > 1)
	{
		stack_b = NULL;
		stack_a = NULL;
		stack_a = pr_arg(av + 1);
		if (!ft_cro(stack_a))
		{
			if (ft_lstsize(stack_a) <= 3)
				size_3(&stack_a);
			else if (ft_lstsize(stack_a) <= 5)
				size_5(&stack_a, &stack_b);
			else if (ft_lstsize(stack_a) > 5)
				size(&stack_a, &stack_b);
		}
	}
	lb(0, 10);
}
