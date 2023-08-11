/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:24:42 by ltressen          #+#    #+#             */
/*   Updated: 2023/07/04 10:40:53 by jcasades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env_alpha(t_data *data)
{
	int		i;
	int		j;
	int		pos;
	char	**new_cpy;

	i = -1;
	new_cpy = ft_calloc((data->env_len + 1), sizeof(char *));
	while (++i < data->env_len)
	{
		pos = 0;
		j = -1;
		while (++j < data->env_len)
		{
			if (ft_strncmp(data->env_cpy[i], data->env_cpy[j], 10000) > 0)
				pos++;
		}
		new_cpy[pos] = ft_strdup(data->env_cpy[i]);
	}
	i = -1;
	while (++i < data->env_len)
	{
		ft_printf("declare -x %s\n", new_cpy[i]);
		free(new_cpy[i]);
	}
	free(new_cpy);
}

void	ft_new_export(t_data *data, char *c)
{
	int		j;
	char	**new_cpy;

	j = 0;
	data->env_len++;
	new_cpy = ft_calloc((data->env_len + 1), sizeof(char *));
	while (data->env_cpy[j])
	{
		new_cpy[j] = ft_strdup(data->env_cpy[j]);
		free (data->env_cpy[j]);
		j++;
	}
	free(data->env_cpy);
	new_cpy[j] = ft_strdup(c);
	data->env_cpy = new_cpy;
}

void	ft_export(t_data *data, char *prompt)
{
	int		i;
	char	**sp;
	int		j;

	j = 0;
	sp = ft_split(prompt, ' ');
	i = 0;
	if (!sp[1])
		ft_env_alpha(data);
	while (sp[++i])
	{
		while (data->env_cpy[j])
		{
			if (!strncmp(data->env_cpy[j], sp[i], ft_lenvar(sp[i]) + 1))
			{
				free(data->env_cpy[j]);
				data->env_cpy[j] = sp[i];
				break ;
			}
			j++;
		}
		if (!data->env_cpy[j])
			ft_new_export(data, sp[i]);
	}
	ft_freesplit(sp);
}
