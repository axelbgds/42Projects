#ifndef __PUSH_SWAP__H
#define __PUSH_SWAP__H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef enum
{
	false,
	true
}Bool;

/* Definition d'une liste */
typedef struct ListElement
{
	int value;
	struct ListElement *next;
}ListElement, *List;

/* Proto */
List	new_list(void);			// ft_lst_new si vide = NULL
Bool 	is_empty_list(List li); // verifie si vide
int 	list_length(List li); 	// ft_lstsize taille
void 	print_list(List li);	// affiche liste
List 	push_back_list(List li, int x); 	//pa = ajoute un el en fin list
List 	push_front_list(List li, int x); 	//pb = ajoute un el au dbt list
List 	pop_back_list(List li);	// retirer second elmt de liste
List 	pop_front_list(List li);// retirer first elmt de liste 

#endif