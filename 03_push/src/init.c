/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perp.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:41:51 by abeaugra          #+#    #+#             */
/*   Updated: 2023/03/07 13:46:30 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* fill_stack_values:
*	Fills stack_a with the provided values.
*	If the values are out of integer range, prints and error and exits the program.
*/

t_stack *fill_stack_value(int ac, char **av)
{
    t_stack     *stack_a;
    long int    nb;
    int         i;

    stack_a = NULL;
    nb = 0;
    while(++i < ac)
    {
        nb = ft_atoi(av[i]);
        if(nb > INT_MAX || nb < INT_MIN)
            exit_error(&stack_a, NULL);
        if(i==1)
            stack_a = stack_new((int)nb);
        else
            stack_add_bottom(&stack_a, stack_new((int)nb));
        i++;
    }
    return(stack_a);
}


/* assign_index:
*	Assigns an index to each value in stack a. This is a convenient way to order
*	the stack because indexes can be checked and compared instead of actual values,
*	which may or may not be adjacent to each other.
*		ex. values:		-3	 0	 9	 2
*		indexes:		[1]	[2]	[4]	[3]
*	The indexes are assigned from highest (stack_size) to lowest (1).
*/

void assign_index(t_stack *stack_a, int stack_size)
{
        t_stack *ptr;
        t_stack *high;
        int value;

        while(--stack_size > 0)
        {
            ptr = stack_a;
            value = INT_MIN;
            high = NULL;
            while(ptr)
            {
                if(ptr->value == INT_MIN && ptr->index == 0)
                    ptr->index = 1;
                if(ptr->value > value && ptr->index == 0)
                {
                    value = ptr->value;
                    high = ptr;
                    ptr = stack_a;
                }
                else
                    ptr = ptr->next;
            }
            if(high != NULL)
                high->index = stack_size;
        }
}

/*
La boucle while parcourt chaque élément de la pile et recherche l'élément non indexé avec la valeur la plus élevée.

La première condition dans la boucle if(ptr->value == INT_MIN && ptr->index == 0) vérifie si l'élément actuel de la pile n'a pas encore été indexé, 
en vérifiant si la valeur index de l'élément est égale à 0. Si l'élément n'a pas encore été indexé, alors la condition vérifie également si la valeur de 
value de l'élément est égale à INT_MIN, qui est la valeur minimale possible pour un entier. Si la valeur de value est INT_MIN, cela signifie que la valeur de 
l'élément n'a pas été initialisée et doit être initialisée avec 1.

La deuxième condition dans la boucle if(ptr->value > value && ptr->index == 0) vérifie si la valeur de l'élément actuel de la pile est supérieure à la valeur 
actuellement stockée dans value. Si la valeur de l'élément est plus grande que value, cela signifie que l'élément a une valeur plus élevée que tous les éléments 
précédents non indexés et qu'il doit être indexé en conséquence. Cette condition vérifie également que l'élément n'a pas encore été indexé, en vérifiant si la 
valeur index de l'élément est égale à 0.

Si la deuxième condition est vraie, la valeur de value est mise à jour avec la valeur de l'élément actuel et le pointeur high est mis à jour pour pointer sur 
l'élément actuel. Ensuite, le pointeur ptr est réinitialisé pour pointer sur le début de la pile stack_a pour parcourir à nouveau tous les éléments de la pile 
et trouver l'élément avec la valeur la plus élevée non indexée. Si la deuxième condition n'est pas vraie, le pointeur ptr est simplement mis à jour pour pointer 
sur l'élément suivant de la pile.
*/