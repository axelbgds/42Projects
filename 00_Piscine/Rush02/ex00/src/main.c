/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:50:50 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/13 23:38:44 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "parser.h"
#include "structs.h"

int	exiter(int status, struct s_dict_entry *entries, int entryc)
{
	int	i;

	i = 0;
	while (i < entryc)
	{
		free(entries[i].word);
		i++;
	}
	free(entries);
	return (status);
}

char	*calc_name(int argc, char *str)
{
	if (argc == 2)
		return ("dict.txt");
	else
		return (str);
}

int	main(int argc, char **argv)
{
	struct s_dict_entry	*entries;
	char				*name;
	int					entryc;
	int					valid;

	if (argc == 2 || argc == 3)
	{
		name = calc_name(argc, argv[2]);
		if (parse_dictionary(name, &entries, &entryc) == 0)
		{
			valid = validate_number(entries, entryc, argv[1]);
			if (valid == 0)
				display_number(entries, entryc, argv[1]);
			else if (valid == -1)
				write(1, "error\n", 6);
			else if (valid == -2)
				write(1, "Dict Error\n", 11);
		}
		else
		{
			write(1, "Dict Error\n", 11);
		}
		return (exiter(0, entries, entryc));
	}
}
