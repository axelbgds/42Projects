/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:35:30 by abeaugra          #+#    #+#             */
/*   Updated: 2023/08/28 14:19:36 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini.h"

void	ft_cpy_env(t_data *data, int i)
{
	char	**unset_cpy;
	int		j;
	int		k;

	unset_cpy = ft_calloc(data->env_len + 1, sizeof(char *));
	j = 0;
	k = 0;
	while (data->env_cpy[j])
	{
		if (i == j)
			j++;
		if (data->env_cpy[j])
			unset_cpy[k++] = ft_strdup(data->env_cpy[j++]);
	}
	ft_freesplit(data->env_cpy);
	data->env_cpy = unset_cpy;
}

int	ft_arg_unset(t_data *data, char *arg)
{
	int	i;

	i = -1;
	while (data->env_cpy[++i])
		if (!ft_strncmp(data->env_cpy[i], arg, ft_strlen(arg)))
			break ;
	if (data->env_cpy[i])
	{
		data->env_len--;
		ft_cpy_env(data, i);
	}
	return (0);
}

int	ft_unset(t_data *data, char *prompt)
{
	char	**split;
	int		i;

	split = ft_split(prompt, ' ');
	i = 0;
	if (!split[1])
	{
		ft_freesplit(split);
		return (0);
	}
	while (split[++i])
		ft_arg_unset(data, split[i]);
	ft_freesplit(split);
	return (0);
}
