/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:36:32 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/12 18:12:38 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_UTILS_H
# define PARSER_UTILS_H

int				parser_intlen(char *str);
int				parser_atoi(char *str, unsigned int n);
unsigned int	parser_wordlen(char *str);
void			parser_word_copy(char *dest, char *src);

#endif
