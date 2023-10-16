/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 10:41:11 by abeaugra          #+#    #+#             */
/*   Updated: 2023/08/30 14:16:09 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini.h"

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
		ft_printf("declare -x %s\n", new_cpy[i]);
	ft_freesplit(new_cpy);
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
		free(data->env_cpy[j]);
		j++;
	}
	free(data->env_cpy);
	new_cpy[j] = ft_strdup(c);
	data->env_cpy = new_cpy;
}

static void	ft_checkenv(t_data *data, char **sp, int i, int j)
{
	while (data->env_cpy[j])
	{
		if (!strncmp(data->env_cpy[j], sp[i], ft_lenvar(sp[i])))
		{
			free(data->env_cpy[j]);
			data->env_cpy[j] = ft_strdup(sp[i]);
			return ;
		}
		j++;
	}
	ft_new_export(data, sp[i]);
}

static void	ft_checkexport(t_data *data, char **sp, int i)
{
	int		j;

	j = 0;
	while (sp[++i])
	{
		if (!ft_isalpha((int)sp[i][j]))
		{
			ft_printf("export: '%s': not a valid identifier\n", sp[i]);
			return ;
		}
	}
	i = 0;
	while (sp[++i])
	{
		ft_checkenv(data, sp, i, j);
	}
}

void	ft_export(t_data *data, char *prompt)
{
	char	**sp;
	int		i;

	i = 0;
	sp = ft_split(prompt, ' ');
	if (!sp[1])
		ft_env_alpha(data);
	else
		ft_checkexport(data, sp, i);
	ft_freesplit(sp);
}
