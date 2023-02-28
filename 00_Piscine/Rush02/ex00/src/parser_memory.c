/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_memory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:52:38 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/13 17:31:54 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "structs.h"

void	*ft_memcpy(void *dest, void *src, unsigned int n)
{
	char	*ret;

	ret = dest;
	while (n)
	{
		((unsigned char *)dest)[0] = ((unsigned char *)src)[0];
		dest++;
		src++;
		n--;
	}
	return (ret);
}

/* je peux pas faire le meme proto que realloc */
/* vu que je connais pas la taille du bloc */
void	*ft_realloc(void *old, unsigned int old_size, unsigned int new_size)
{
	void	*new;

	new = malloc(new_size);
	if (new == 0)
		return (0);
	if (old != 0)
		ft_memcpy(new, old, old_size);
	free(old);
	return (new);
}

int	dict_entry_alloc(struct s_dict_entry **entries, int *entryc)
{
	struct s_dict_entry	*new;

	entryc[0]++;
	new = ft_realloc(
			entries[0],
			(entryc[0] - 1) * sizeof(struct s_dict_entry),
			entryc[0] * sizeof(struct s_dict_entry)
			);
	if (new == 0)
	{
		entryc[0]--;
		return (-1);
	}
	entries[0] = new;
	entries[0][entryc[0] - 1].word = 0;
	return (0);
}
