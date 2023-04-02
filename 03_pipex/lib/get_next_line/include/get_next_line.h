#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_strjoin_m(char *s1, char *s2);
size_t	ft_strlen_gnl(const char *s);
void	*ft_memcpy_gnl(void *dst, const void *src, size_t n);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_substr_m(char const *s, unsigned int start, size_t len);

#endif
