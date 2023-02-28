/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_memory.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:02:12 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/13 09:54:55 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_MEMORY_H
# define PARSER_MEMORY_H

# include "structs.h"

void	*ft_memcpy(void *dest, void *src, unsigned int n);
void	*ft_realloc(void *old, unsigned int old_size, unsigned int new_size);
int		dict_entry_alloc(struct s_dict_entry **entries, int *entryc);

#endif
