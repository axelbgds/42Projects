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
#define __PUSH_SWAP_H__

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
    -> init.c = OK */
t_stack *fill_stack_value(int ac, char **av);
void assign_index(t_stack *stack_a, int ac);

/* Position
    -> pos.c = OK*/
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
    -> func_stack.c = OK*/
t_stack *new_stack(int value);
int length_stack(t_stack *stack);
t_stack *last_stack(t_stack *stack);
void add_last_stack(t_stack **stack, t_stack *new);
t_stack *get_twice_last_stack(t_stack *stack);

/* Utils
    -> utils.c = OK*/
long int ft_atoi(const char *str);
void ft_putstr(char *str);
int nb_abs(int nb);
void free_stack(t_stack **stack);
void exit_error(t_stack **stack_a, t_stack **stack_b);

/* Input
    -> input1.c input2.c = OK*/
int is_correct_input(char **av);
int is_digit(char c);
int is_sign(char c);
int nbstr_cmp(const char *s1, const char *s2);
int  arg_is_number(char *av);
int  twice(char **av);
int  arg_zero(char *av);
int is_correct(char **av);

/* Sort Algo
    -> sort_small.c sort_big.c = OK*/
int is_sorted(t_stack *stack);
void small_sort(t_stack **stack);
void big_sort(t_stack **stack_a, t_stack **stack_b);

#endif