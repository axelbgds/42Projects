#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
# include <stdbool.h>

/* Parsing
	-> check_arg.c */
int		char_to_int(char *str);
t_lst	*char_to_list(char **av);
void	check_space(char **av);
t_lst	*put_arg(char **av);
bool	ft_croissant(t_lst *lst);

/* Free liste
	-> clear_lst.c */
void    *clear_lst(size_t size, int param);

/* Trie de la liste
	-> list_sortb.c list_sorta.c */
void    push_node_a(t_lst **lst_a, t_lst **lst_b, t_lst *node);
void    push_node_b(t_lst **lst_a, t_lst **lst_b, t_lst *node);
void    push_smallest_to_a(t_lst **lst_a, t_lst **lst_b, t_lst *node);
void    push_last(t_lst **lst_a, t_lst **lst_b, t_lst *node);
void    *get_top_elmt(t_lst *lst, t_lst *node);

/* Instructions stack 
	-> os_swap.c os_push.c os_rotate.c os_rev_rot.c */
void	sa(t_lst **lst_a, int flag);
void	sb(t_lst **lst_b, int flag);
void	ss(t_lst **lst_a, t_lst **lst_b, int flag);
void	pa(t_lst **lst_a, t_lst **lst_b, int flag);
void	pb(t_lst **lst_b, int flag, t_lst **lst_a);
void	ra(t_lst **lst_a, int flag);
void	rb(t_lst **lst_b, int flag);
void	rr(t_lst **lst_a, t_lst **lst_b, int flag);
void	rra(t_lst **stack, int flag);
void	rrb(t_lst **stack, int flag);
void	rrrt_list(t_lst **lst_a, t_lst **lst_b, int flag);

/* 
	-> */


#endif
