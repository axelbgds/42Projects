/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:19:24 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/13 18:57:19 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "structs.h"
#include "parser_read.h"
#include "parser_utils.h"
#include "parser_memory.h"

int	parse_line(char *str, struct s_dict_entry *entry)
{
	int	len;

	if (str[0] < '0' || str[0] > '9')
		return (-1);
	len = parser_intlen(str);
	entry->num = parser_atoi(str, len);
	if (entry->num < 0)
		return (-1);
	str += len;
	entry->zero = 0;
	while (str[entry->zero] == '0')
		entry->zero++;
	str += entry->zero;
	while (str[0] == ' ')
		str++;
	if (str[0] != ':')
		return (-1);
	str++;
	while (str[0] == ' ')
		str++;
	entry->word = malloc(parser_wordlen(str) + 1);
	if (entry->word == 0)
		return (-1);
	parser_word_copy(entry->word, str);
	return (0);
}

int	parser_manage_line(
		char *line,
		struct s_dict_entry **entries,
		int *entryc,
		int *ret)
{
	if (parse_line(line, entries[0] + (entryc[0] - 1)) < 0)
	{
		ret[0] = -1;
		return (-1);
	}
	if (dict_entry_alloc(entries, entryc) < 0)
	{
		ret[0] = -1;
		return (-1);
	}
	return (0);
}

int	parser_dictionary_exit(char *line, int fd, int *entryc, int ret)
{
	entryc[0]--;
	free(line);
	close(fd);
	if (ret < 0)
		return (-1);
	else
		return (0);
}

int	parse_dictionary(
		char *filename,
		struct s_dict_entry **entries,
		int *entryc)
{
	int				fd;
	char			*line;
	unsigned int	buffsize;
	int				ret;

	entryc[0] = 0;
	line = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0 || dict_entry_alloc(entries, entryc) < 0)
		return (-1);
	while (1)
	{
		ret = parser_read_line(fd, &line, &buffsize);
		if (ret < 0)
			break ;
		if (line[0] == 0 && ret == 1)
			continue ;
		else if (line[0] == 0)
			break ;
		if (parser_manage_line(line, entries, entryc, &ret) < 0)
			break ;
		if (ret == 0)
			break ;
	}
	return (parser_dictionary_exit(line, fd, entryc, ret));
}
