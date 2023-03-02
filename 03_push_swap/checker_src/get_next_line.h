/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h  		                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.fr>   +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:45:39 by ddupont           #+#    #+#             */
/*   Updated: 2022/03/31 21:51:48 by ddupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GNL_H__
# define __GNL_H__

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h> // verifier pour printf

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		nl_isin(const char *s);
char	*ft_strjoin(char *s1, const char *s2);
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);

#endif