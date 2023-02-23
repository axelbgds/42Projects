#include "stdio.h"
#include "push_swap.h"

/*
La pile a contient une quantité aléatoire de négatif 
et/ou des nombres positifs qui ne peuvent pas être 
dupliqués.◦ La pile b est vide.
*/

int main(void)
{
	List my_list = new_list();

	print_list(my_list);
	my_list = push_back_list(my_list,36);
	print_list(my_list);

	my_list = push_back_list(my_list,156);
	my_list = push_front_list(my_list,86);
	my_list = push_back_list(my_list,91);
	print_list(my_list);

	my_list = pop_back_list(my_list);
	my_list = pop_back_list(my_list);
	print_list(my_list);


	return(0); 
}