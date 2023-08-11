/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:12:04 by tde-los-          #+#    #+#             */
/*   Updated: 2023/02/21 10:56:33 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		gnl_ft_strchr(char *str, char c);
char	*get_next_line(int fd);
char	*ft_line(char *statsh);
char	*free_statsh(char *statsh);
char	*buff_and_read(int fd, char *statsh);
char	*gnl_ft_strjoin(char *s1, char *s2);
char	*gnl_ft_strdup(char *s);
size_t	gnl_ft_strlen(char *str);

#endif
