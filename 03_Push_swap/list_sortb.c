/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sortb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perp.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:15:56 by abeaugra          #+#    #+#             */
/*   Updated: 2023/03/17 13:15:18 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_push_swap.h"

/*
* La fonction push_node_a déplace un élément de la pile B vers la pile A tout en 
* effectuant des rotations pour optimiser la position de l'élément dans la pile A.
*
* Les fonctions push_node_stack_b, push_smallest_to_a et push_last sont similaires à 
* push_node_a, mais effectuent des rotations et des inversions de piles 
* différentes pour optimiser la position de l'élément dans la pile A.
*
* La fonction get_top_elmt retourne l'élément dans la pile qui est le plus proche de 
* l'élément donné et qui est supérieur à cet élément, afin de déterminer la position
* optimale pour insérer un élément dans la pile.
*/

// Déplace un nœud vers la lst_a
void    push_node_a(t_lst **lst_a, t_lst **lst_b, t_lst *node)
{
    int rotate_b = node->pos_b;
    int rotate_a = node->address->pos_b;

    while (rotate_b && rotate_a)
    {
        rr(lst_a, lst_b, 1);
        rotate_a--;
        rotate_b--;
    }
    while (rotate_b--)
        rb(lst_b, 1);
    while (rotate_a--)
        ra(lst_a, 1);
    pa(lst_b, lst_a, 1);
}

// Déplace un nœud vers la lst_b
void    push_node_b(t_lst **lst_a, t_lst **lst_b, t_lst *node)
{
    int keep_a = node->address->pos_b;
    int keep_b = node->pos_b;
    
    if (keep_a > keep_b)
    {
        while (keep_a > keep_b)
            rra(lst_a, 1);
        while (keep_b--)
            rrr(lst_a, lst_b, 1);
    }
    else
    {
        while (keep_b-- > keep_a)
            rrb (lst_b,1);
        while (keep_a--)
            rrr(lst_a, lst_b, 1);
    }
    pa(lst_b, lst_a, 1);
}

// Push petit elmt de lst_b dans lst_a
void    push_smallest_to_a(t_lst **lst_a, t_lst **lst_b, t_lst *node)
{
    int moves_a;
    int moves_b;

    moves_a = 0;
    while(node->address->pos_b - moves_a > 0)
    {
        moves_a++;
        rr(lst_a, lst_b, 1);
    }
    moves_b = 0;
    while (node->pos_b - moves_b > 0)
    {
        moves_b++;
        rr(lst_a, lst_b, 2);
    }
    pa(lst_b, lst_a, 1);
}

// Push last elmt sur l'autre lst
void    push_last(t_lst **lst_a, t_lst **lst_b, t_lst *node)
{
    while (node->address->pos_b)
    {
        rra(lst_a, 1);
        node->address->pos_b--;
    }
    while (node->pos_b)
    {
        rb(lst_b, 1);
        node->pos_b;
    }
    pa(lst_a, lst_b, 1);
}

// Renvoie un * sur elemt lst qui > a elmt node
void    *get_top_elmt(t_lst *lst, t_lst *node)
{
    t_lst  *top;

    top = getmin(lst);
    while (lst)
    {
        if (lst->pos_b > node->pos_b && lst->pos_b < top->pos_b)
            top = lst;
        lst = lst->next;
    }
    return (top);
}