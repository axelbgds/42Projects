/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:20:44 by abeaugra          #+#    #+#             */
/*   Updated: 2023/06/27 11:27:12 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void		add_args(char **argv, t_stack **stack_a);
void		ft_add_back(t_stack **stack, t_stack *stack_new);
t_stack		*ft_new_stack(int content);
int			check_args(char **argv);
void		alpha_check(char **argv);
int			check_error(char **argv, int i, int j);
int			check_dup(t_stack *a);
int			ft_isalpha(int c);
int			sign(int c);
int			digit(int c);
int			space(int c);
int			space_atoi(char *str);
void		ft_error(void);
void		stack_free(t_stack **lst);
t_stack		*ft_lstlast(t_stack *lst);
void		ra(t_stack **a, int j);
void		rb(t_stack **b, int j);
void		sa(t_stack **a, int j);
void		pa(t_stack **a, t_stack **b, int j);
void		pb(t_stack **stack_a, t_stack **stack_b, int j);
void		rra(t_stack **a, int j);
void		ss(t_stack **a, t_stack **b, int j);
void		rr(t_stack **a, t_stack **b, int j);
void		rrr_sub(t_stack **b, int j);
void		rrr(t_stack **a, t_stack **b, int j);
t_stack		*ft_lstlast(t_stack *lst);
int			ft_lstsize(t_stack *lst);
int			ft_min(t_stack *a);
int			ft_max(t_stack *a);
int			find_index(t_stack *a, int nbr);
int			find_place_b(t_stack *stack_b, int nbr_push);
int			find_place_a(t_stack *a, int nbr);
void		sort(t_stack **stack_a);
int			check_sort(t_stack *stack_a);
void		sort(t_stack **stack_a);
void		sort_3(t_stack **stack_a);
t_stack		*parse(int argc, char **argv);
t_stack		*parse_args_quote(char **argv);
void		freestr(char **lst);
int			case_rarb_a(t_stack *a, t_stack *b, int c);
int			case_rrarrb_a(t_stack *a, t_stack *b, int c);
int			case_rarrb_a(t_stack *a, t_stack *b, int c);
int			case_rrarb_a(t_stack *a, t_stack *b, int c);
int			case_rarb(t_stack *a, t_stack *b, int c);
int			case_rrarrb(t_stack *a, t_stack *b, int c);
int			case_rrarb(t_stack *a, t_stack *b, int c);
int			case_rarrb(t_stack *a, t_stack *b, int c);
int			rotate_ab(t_stack *a, t_stack *b);
int			rotate_ba(t_stack *a, t_stack *b);
int			rarb(t_stack **a, t_stack **b, int c, char s);
int			rrarrb(t_stack **a, t_stack **b, int c, char s);
int			rrarb(t_stack **a, t_stack **b, int c, char s);
int			rarrb(t_stack **a, t_stack **b, int c, char s);
void		rrb(t_stack **b, int j);
t_stack		*process(int argc, char **argv);
void		sb(t_stack **b, int j);
void		sortb_3(t_stack **stack_a, t_stack **stack_b);
t_stack		*sub_process(char **argv);
void		ft_error_ch(void);
char		*ft_check(t_stack **a, t_stack **b, char *line);
void		ft_check_ope(t_stack **a, t_stack **b, char *line);
void		ft_check_stack(t_stack **a, t_stack **b, char *line);

#endif
