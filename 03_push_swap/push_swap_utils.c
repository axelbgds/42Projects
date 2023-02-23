#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

List	new_list(void)
{
	return NULL;
}

/* ----------------------------- */

Bool 	is_empty_list(List li)
{
	if(li == NULL)
		return true;
	return false;
}

/* ----------------------------- */

int 	list_length(List li)
{
	int	size;

	size = 0;
	if(is_empty_list(li))
	{
		while(li != NULL)
		{
			++size;
			li = li->next;
		}
		return size;
	}
}

/* ----------------------------- */

void 	print_list(List li)
{
	if(is_empty_list(li))
	{
		printf("Rien a afficher, la liste est vide\n");
		return;
	}
	while(li != NULL)
	{
		printf("[%d]", li->value);
		li = li->next;
	}
	printf("\n");
}

/* ----------------------------- */

List 	push_back_list(List li, int x)
{
	ListElement *element; 				// cree nouvelle elmt

	element = malloc(sizeof(*element)); // taille de elmt
	if(element == NULL)
	{
		fprintf(stderr, "Erreur : Pb allocation dynamique");
		exit(EXIT_FAILURE);
	}
	element->value = x;			// attribu x a la prochaine value
	element->next = NULL;		// sorti de la lst
	if(is_empty_list(li))
		return element;
	ListElement *temp;			// creation de notre tmp
	temp = li;					// reference sur li
	while(temp->next != NULL)	// while != NULL
		temp = temp->next;		// on deplace le ptr
	temp->next = element;		// dernier = elmt
	return li;					// renvoie la reference
}

/* ----------------------------- */

List 	push_front_list(List li, int x)
{
	ListElement *element;

	element = malloc(sizeof(*element));
	if(element == NULL)
	{
		fprintf(stderr, "Erreur : pb allocation dynamique");
		exit(EXIT_FAILURE);
	}
	element->value = x;
	if(is_empty_list(li))
			element->next = NULL;
	else
		element->next = li;
	return element;	// elmt contient tout
}

/* ----------------------------- */

List 	pop_back_list(List li)
{
	if(is_empty_list(li))
		return new_list();
	if(li->next == NULL)
	{
		free(li);
		li = NULL;
		return new_list();
	}

	ListElement *temp = li;
	ListElement *before = li;
	while(temp->next != NULL)
	{
		before = temp; 		// pour perdre la valeur d'avant
		temp = temp->next;	// deplacement de ptr
	}
	before->next = NULL;
	free(temp);
	temp = NULL;
	return(li);
}

/* ----------------------------- */

List 	pop_front_list(List li)
{
	ListElement *element;

	if(is_empty_list(li))
		return li;
	element = malloc(sizeof(*element));
	if(element == NULL)
	{
		fprintf(stderr, "Erreur : pb allocation dynamique");
		exit(EXIT_FAILURE);
	}
	element = li->next;
	free(li);
	li = NULL;
	return element;
}

