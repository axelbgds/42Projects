/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:15:22 by alsaez            #+#    #+#             */
/*   Updated: 2023/09/18 22:25:03 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

// PRESENT DEUX FOIS ?
char	*store_rest(char *buff);
char	*store_txt(int fd, char *buff);
char	*get_next_line(int fd);
char	*ft_read_to_str(int fd, char *str);
char	*getlinef(char *buff);
char	*ft_nextline(char *buf);

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);

typedef struct s_flags
{
	int				type;
	int				width;
	int				minus;
	int				hash;
	int				space;
	int				zero;
	int				dot;
	int				star;
}					t_flags;

int		ft_printf(const char *str, ...);
int		ft_is_in_type_list(int c);
int		ft_is_in_flags_list(int c);
int		ft_treatment(int c, t_flags flags, va_list args);
int		ft_treat_width(int width, int minus, int has_zero);
int		ft_putstrprec(char *str, int prec);
int		ft_treat_char(char c, t_flags flags);
int		ft_treat_dot_len(char *str_i, t_flags flags);
int		ft_treat_string(char *str, t_flags flags);
int		ft_treat_int(int i, t_flags flags);
int		ft_treat_min_int(int i, t_flags flags);
int		ft_treat_percent(t_flags flags);
int		ft_treat_hexa(unsigned int ui, int lower, t_flags flags);
int		ft_treat_uint(unsigned int unsi, t_flags flags);
int		ft_flag_dot(const char *str, int start, t_flags *flags,
			va_list args);
int		ft_treat_ptr(unsigned long long pointer, t_flags flags);
int		ft_putchar(int c, t_flags flags);

char	*ft_ull_base(unsigned long long ull, int base);
char	*ft_u_itoa(unsigned int n);
char	*ft_str_tolower(char *str);

t_flags	ft_flag_minus(t_flags flags);
t_flags	ft_flag_width(va_list args, t_flags flags);
t_flags	ft_flag_digit(char c, t_flags flags);
t_flags	ft_flag_space(t_flags flags);
t_flags	ft_flag_hash(t_flags flags);
t_flags	ft_flag_plus(t_flags flags);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_islower(int c);
int		ft_isupper(int c);

int		ft_toupper(int c);
int		ft_tolower(int c);

void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strdup(const char *s);

int		ft_atoi(const char *str);
char	*ft_itoa(int n);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(char *s1, char *s2);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

char	*get_next_line(int fd);
char	*store_txt(int fd, char *buff);
char	*get_linef(char *buff);
char	*store_rest(char *buff);
char	*ft_strcpy(char *buff, char *str, int i);
char	*ft_strchrgnl(char *str, char c);
char	*ft_strjoingnl(char *s1, const char *s2);
size_t	ft_strlcatgnl(char *dst, const char *src, size_t size);

#endif
