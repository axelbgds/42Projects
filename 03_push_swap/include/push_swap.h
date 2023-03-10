
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>

typdef struct s_stack
{
	int	data;
	int	pos_a;
	int	pos_b;
	struct s_stack *next;
}


/* Initialisation
	-> init.c */


/* Position
	-> */

/* Operation stack 
	-> stack.c */
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a);
void	pb(t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

/* Input 
	-> input.c */


#endif
