#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef enum
{
	true,  //1
	false, //0
} 	Bool;

typedef struct s_list
{
	int		size;
	int 	*array;
}			t_list;

/* Utils
    -> utils1.c = OK*/
int 	ft_atoi(const char *str);
void	ft_putstr(char *str);
int 	nb_abs(int nb);
int 	ft_strncmp(const char *s1, const char *s2, size_t n);
size_t  ft_strlen(const char *str);

/* Stack function
    -> stack_func.c = OK*/
t_list *new_stack(int size);
void	init_stack(int ac, char **av);
void	init_stack(int ac, char **av);

/* Check error
	-> error.c */
void	exit_error(t_list *a, t_list *b);

/* Check input
    -> check_input.c = OK*/
int 	is_digit(char c);
int		is_sign(char c);
int 	check_arg(char **str);
int		check_twice(char **str);
int 	check_input(char **str);

/* Operations stack
    -> os_swap.c os_push.c os_rot.c os_rev_rot.c */
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b)
void	rr(t_list **stack_a, t_list **stack_b);




#endif