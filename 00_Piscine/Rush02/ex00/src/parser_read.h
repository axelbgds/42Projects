/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_read.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:15:31 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/12 18:12:13 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_READ_H
# define PARSER_READ_H

int	parser_read_line(int fd, char **line, unsigned int *buffsize);

#endif
