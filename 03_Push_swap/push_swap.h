/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perp.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:28:38 by abeaugra          #+#    #+#             */
/*   Updated: 2023/06/19 21:31:46 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_stacks
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_stacks;

// checker.c

void	ft_checker(char *av[]);
void	ft_checker_next(t_stacks *stack);
int		ft_check_ope(char *opt, t_stacks *stack);
void	ft_ope(t_stacks *stack, char *opt);

// get_next_line.c

char	*get_next_line(int fd);

// push_swap_printf.c

int		ft_printf(const char *str, ...);

// push_swap_quicksort.c

void	ft_quicksort_3(t_stacks *stack, int len);
int		ft_get_mediane(int *pivot, int *stack, int size);
int		ft_sort_small_b(t_stacks *stack, int len);
int		ft_quicksort_b(t_stacks *stack, int len, int cnt);
int		ft_quicksort_a(t_stacks *stack, int len, int cnt);

// push_swap_rules_four.c

void	ft_sa(t_stacks *stack, int print);
void	ft_sb(t_stacks *stack, int print);
void	ft_ss(t_stacks *stack, int print);

// push_swap_rules_three.c

void	ft_rra(t_stacks *stack, int print);
void	ft_rrb(t_stacks *stack, int print);
void	ft_rrr(t_stacks *stack, int print);

// push_swap_rules_two.c

void	ft_ra(t_stacks *stack, int print);
void	ft_rb(t_stacks *stack, int print);
void	ft_rr(t_stacks *stack, int print);

// push_swap_rules.c

void	ft_pb(t_stacks *stack, int print);
void	ft_pa(t_stacks *stack, int print);

// push_swap_sort.c

void	ft_sort_tmp(int *tmp_stack, int size);
int		ft_push(t_stacks *stack, int len, int operation);
void	ft_sort_three_a(t_stacks *s);
int		ft_sort(t_stacks *stack, int size);

// push_swap_split_utils.c

size_t	ft_ps_strlen(char **str);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		ft_strcmp(const char *s1, const char *s2);

// push_swap_split.c

char	*ft_strdup(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	word_count(const char *s, char c);
char	*ft_strcreate(const char *s, char c, size_t counter);
char	**ft_split(char const *s, char c);

// push_swap_utils.c

void	ft_error(int *stack);
void	ft_check_repeat(int *stack, int size);
int		ft_check_sorted(int *stack, int size, int order);
int		ft_ps_atoi(char *str, int *stack);

// push_swap.c

void	ft_push_swap(char *av[]);

#endif
