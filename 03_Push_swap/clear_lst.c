/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perp.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:36:37 by abeaugra          #+#    #+#             */
/*   Updated: 2023/03/16 11:55:13 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_push_swap.h"

/*
** Cette fonction gère la gestion de la mémoire en utilisant une liste chaînée
** pour stocker les adresses allouées avec malloc. Elle prend deux paramètres :
** - size : la taille de la mémoire à allouer
** - param : un indicateur pour spécifier l'action à effectuer :
**           - 1 pour allouer la mémoire
**           - 0 pour libérer la mémoire et quitter le programme avec un code de sortie 1
**           - tout autre valeur pour libérer la mémoire et quitter le programme avec un code de sortie 0
*/

void    *clear_lst(size_t size, int param)
{
    static t_lst   *memory_blocks;
    void            *allocated_memory;
    t_lst          *new_block_node;

    if (param == 1)
    {
        allocated_memory = malloc(size);
        if (!allocated_memory)
        {
            ft_lstclear(&memory_blocks, free);
            exit(1);
        }
        new_block_node = malloc(sizeof(t_lst));
        if (!new_block_node)
        {
            free(allocated_memory);
            ft_lstclear(&memory_blocks, free);
            exit(1);
        }
        new_block_node->address = allocated_memory;
        new_block_node->next = NULL;
        ft_lstadd_front(&memory_blocks, new_block_node);
        return (allocated_memory);
    }
    else if (param == 0)
    {
        ft_lstclear(&memory_blocks, free);
        exit(1);
    }
    else
    {
        ft_lstclear(&memory_blocks, free);
        exit (0);
    }
}
