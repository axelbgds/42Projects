/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:49:23 by abeaugra          #+#    #+#             */
/*   Updated: 2023/02/27 19:53:36 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PUSH_SWAP__
#define __PUSH_SWAP__

#include <unistd.h>
#include <stdlib.h>

typedef enum
{
	false, 	// 0
	true	// 1
}Bool;

typedef struct		s_stack
{
	int 			data;
	struct s_stack	*next;
}	t_stack;

/* Parsing functions
	-> parsing.c */
int		check_duplicate(int *array, int size);
int 	ft_isdigit(int c);
int 	ft_isspace(int c);
int 	ft_atoi(const char *str);
int 	check_args(int ac, char **av, int *array, int size);

/* Stack operations 
	-> stack_ope1.c stack_ope2.c */
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void 	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void 	rrr(t_stack **a, t_stack **b);

/* Function for handling stack operations	
	-> function_stack.c */
t_stack	new_stack(void);
Bool	is_empty(t_stack *s);
void	init_stack(t_stack *s, int size);
void	print_stack(void);
t_stack	clear_stack(t_stack st);	// free
void	push_stack(t_stack *st, int x);
int 	pop_stack(t_stack *st);
int		peek_stack(t_stack *st);
// void	free_stack(t_stack *s);
// int		is_full(t_stack *s);

/* Sort ALGO
	-> sort_push_swap.c*/
void	sort_small(t_stack **a, t_stack **b, int size);
void	sort_medium(t_stack **a, t_stack **b, int size);
void 	sort_large(t_stack **a, t_stack **b, int size);

#endif