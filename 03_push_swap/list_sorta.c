/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sorta.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perp.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:39:13 by abeaugra          #+#    #+#             */
/*   Updated: 2023/03/17 14:33:01 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_push_swap.h"

/* Attribue à chaque élément d'une liste des index relatifs
** qui indiquent leur position par rapport au centre de la liste. 
** Ces index sont utilisés pour déterminer les mouvements nécessaires 
** pour trier la liste. 
*/

void    assign_relativ_indexes(t_lst *lst)
{
    int i =0;
    int j = ft_lstsize(lst) / 2;


    while(lst)
    {
        if (lst->pos_b = (i <= j))
            i++;
        else 
            j--;
        lst = lst->next;
    }
}

/* Parcourir une liste chaînée et de renvoyer un pointeur vers l'élément ayant
** la valeur la plus petite 
*/

void    find_small(t_lst *sa)
{
    t_lst   *min;
    
    min = sa;
    while(sa)
    {
        if (sa->data < min->data)
            min = sa;
        sa = sa->next;
    } 
}

/* calculer la valeur de "lis" pour chaque élément de la pile B en fonction de sa 
** position dans la pile A et de sa position actuelle dans la pile B.
*/
void    g_moves(t_lst *lst_a, t_lst *lst_b)
{
    t_lst   *tmp;

    g_index(lst_a);
    g_index(lst_b);
    tmp = lst_b;
    while (tmp)
    {
        tmp->address = get_top_elmt(lst_a, tmp);
        int dist = ft_abs(tmp->pos_b - tmp->address->pos_b);
        if (tmp->pos_b < 0 || tmp->address->pos_b < 0)
            tmp->lis = -1 * dist;
        else
            tmp->lis = dist;
        tmp = tmp->next;
    }
}

