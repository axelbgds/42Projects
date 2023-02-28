/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 09:16:27 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/16 12:00:20 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <fcntl.h>

#include "ft/ft_putstr.h"

#define BUFF_LEN 1024

int	cat_err(int ret, char *file)
{
	ft_fdputstr(2, "cat: ");
	ft_fdputstr(2, file);
	ft_fdputstr(2, ": ");
	ft_fdputstr(2, strerror(errno));
	ft_fdputstr(2, "\n");
	return (ret);
}

int	cat_open(char *file)
{
	int fd;

	if (file == 0)
		return (0);
	if (file[0] == '-' && file[1] == 0)
		return (0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (cat_err(fd, file));
	return (fd);
}

#include <stdio.h>

int	cat_file(char *file)
{
	int		fd;
	char	buff[BUFF_LEN];
	int		ret;

	fd = cat_open(file);
	if (fd < 0)
		return (-1);
	while (1)
	{
		ret = read(fd, buff, BUFF_LEN);
		if (ret < 0)
			cat_err(fd, file);
		if (ret <= 0)
			break ;
		write(1, buff, ret);
	}
	close(fd);
	return 0;
}
