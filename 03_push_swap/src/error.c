

#include "push_swap.h"

void	exit_error(t_list *a, t_list *b)
{
	write(2,"Error\n",6);
	free(a->array);
	free(*a);
	free(b->array);
	free(*b);
	exit(1);
}