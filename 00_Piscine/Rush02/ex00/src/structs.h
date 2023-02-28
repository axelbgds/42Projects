/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:52:22 by tsharma           #+#    #+#             */
/*   Updated: 2022/02/13 20:50:33 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

struct s_dict_entry
{
	int		num;
	int		zero;
	char	*word;
};

struct s_dictionary {
	struct s_dict_entry	*en;
	int					enc;
};

int		display_number(struct s_dict_entry *entries, int entryc, char *number);
int		validate_number(struct s_dict_entry *entries, int entryc, char *number);
int		valid_rec(struct s_dict_entry *en, int value, int ze, int ec);
int		ft_strlen(char *str);
void	ft_putstr(char *str, int print_space);
char	*find_number(struct s_dict_entry *en, int num, int zero, int entryc);
void	print_value(int value, int ze, struct s_dictionary dict, int put_space);

#endif
