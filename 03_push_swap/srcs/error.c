/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:32:30 by abeaugra          #+#    #+#             */
/*   Updated: 2023/02/22 17:03:57 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*

Voici les algorithmes :

Algorithme pour trier 5 entiers ou moins en utilisant moins de 5 instructions :

    Si la pile contient 2 éléments, comparer les deux et échanger s'ils sont dans le mauvais ordre.
    Si la pile contient 3 éléments, faire les opérations suivantes :
        Trouver le minimum des trois éléments et le mettre au sommet de la pile.
        Comparer les deux éléments restants et les échanger s'ils sont dans le mauvais ordre.
    Si la pile contient 4 éléments, faire les opérations suivantes :
        Trouver le minimum des quatre éléments et le mettre au sommet de la pile.
        Comparer les deux éléments restants et les échanger s'ils sont dans le mauvais ordre.
        Déplacer le minimum de la pile vers le bas.
    Si la pile contient 5 éléments, faire les opérations suivantes :
        Trouver le minimum et le maximum des cinq éléments.
        Les mettre en haut de la pile, le maximum en premier.
        Trouver le minimum et le maximum des trois éléments restants.
        Les mettre en haut de la pile, le maximum en premier.
        Placer le dernier élément restant en bas de la pile.

Algorithme pour trier plus de 5 entiers en un minimum d'instructions :

    Diviser la pile en deux piles de tailles égales (ou proches).
    Trier chaque pile de manière récursive en utilisant l'algorithme précédent.
    Fusionner les deux piles triées en une seule pile en utilisant les règles suivantes :
        Tant que les deux piles ne sont pas vides, comparer les éléments en haut des deux piles et les 		placer dans l'ordre dans la pile de sortie.
        Si une pile est vide, prendre les éléments restants de l'autre pile et les placer dans la pile de 		sortie.
    La pile de sortie contient maintenant les éléments triés en médiane, avec les plus petits éléments en 	bas et les plus grands en haut.

*/
