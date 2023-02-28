/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 08:25:10 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/16 08:40:37 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#define BUFF_LEN 1024

int	erret(char *str, int s)
{
	write(2, str, s);
	return (1);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	buff[BUFF_LEN];
	int		ret;

	if (argc < 2)
		return (erret("File name missing.\n", 19));
	if (argc > 2)
		return (erret("Too many arguments.\n", 20));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (erret("Cannot read file.\n", 18));
	while (1)
	{
		ret = read(fd, buff, BUFF_LEN);
		if (ret < 0)
		{
			erret("Cannot read file.\n", 18);
			break;
		}
		if (ret == 0)
			break;
		write(1, buff, ret);
	}
	return (0);
}
