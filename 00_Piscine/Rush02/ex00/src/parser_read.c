/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:29:32 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/13 17:30:43 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "ft_strlen.h"
#include "parser_memory.h"

#define ALLOC_SEGMENT 50

int	parser_read_buffsize_check(unsigned int i, char **line,
	unsigned int *buffsize)
{
	char	*new;

	if (i >= buffsize[0])
	{
		new = ft_realloc(line[0], buffsize[0], buffsize[0] + ALLOC_SEGMENT);
		if (new == 0)
			return (-1);
		line[0] = new;
		buffsize[0] = buffsize[0] + ALLOC_SEGMENT;
	}
	return (0);
}

int	parser_read_line(int fd, char **line, unsigned int *buffsize)
{
	char				c;
	unsigned int		i;
	int					ret;

	if (line[0] == 0)
		buffsize[0] = 0;
	i = 0;
	while (1)
	{
		c = 1;
		ret = read(fd, &c, 1);
		if (ret < 0 || c == '\0')
			return (-1);
		if (ret == 0)
			break ;
		if (c == '\n')
			return (1);
		if (parser_read_buffsize_check(i, line, buffsize) < 0)
			return (-1);
		line[0][i] = c;
		line[0][i + 1] = '\0';
		i++;
	}
	line[0][i] = 0;
	return (0);
}
