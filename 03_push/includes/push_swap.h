/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:10:43 by abeaugra          #+#    #+#             */
/*   Updated: 2023/03/06 15:10:43 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PUSH_SWAP_H__
# define __PUSH_SWAP_H__

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

typedef struct s_stack
{
    int value;
    int index;
    int pos;
    int target;
    int len_a;
    int len_b;
    struct s_stack *next;
} t_stack;

/* Initialisation
    -> init.c */
t_stack *fill_stack_value(int ac, char **av);
void assign_index(t_stack *stack_a, int ac);

/* Sort Algo
    -> sort.c */
int is_sorted(t_stack *stack);
void small_sort(t_stack **stack);
void big_sort(t_stack **stack_a, t_stack **stack_b);

/* Position
    -> pos.c */
void get_len(t_stack **stack_a, t_stack **stack_b);
void do_chepeast_moove(t_stack **stack_a, t_stack **stack_b);

/* How many len and calculate the moove
    -> len.c */
void get_len(t_stack **stack_a, t_stack **stack_b); // get_cost
void do_cheapest_move(t_stack **stack_a, t_stack **stack_b);
void do_moove(t_stack **stack_a, t_stack **stack_b, int len_a, int len_b);

/* Operations stack
    -> os_swap.c os_push.c os_rot.c os_rev_rot.c */
void sa(t_stack **stack_a);
void sb(t_stack **stack_b);
void ss(t_stack **stack_a, t_stack **stack_b);
void pa(t_stack **stack_a);
void pb(t_stack **stack_b);
void ra(t_stack **stack_a);
void rb(t_stack **stack_b);
void rr(t_stack **stack_a, t_stack **stack_b);
void rra(t_stack **stack_a);
void rrb(t_stack **stack_b);
void rrr(t_stack **stack_a, t_stack **stack_b);

/* Function stack
    -> func_stack.c */
t_stack *stack_new(int value);
int get_stack_size(t_stack *stack);
void stack_add_bottom(t_stack **stack, t_stack *new);
t_stack *get_stack_bottom(t_stack *stack);
t_stack *get_stack_before_bottom(t_stack *stack);

/* Utils
    -> utils.c */
long int ft_atoi(const char *str);
void ft_putstr(char *str);
int nb_abs(int nb);
void free_stack(t_stack **stack);

/* Error
    -> error.c */
void exit_error(t_stack **stack_a, t_stack **stack_b);

/* Input 
    -> input.c */
int is_correct_input(char **av);
int is_digit(char c);
int is_sign(char c);
int nbstr_cmp(const char *s1, const char *s2);

#endif