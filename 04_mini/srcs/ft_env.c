/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:30:03 by abeaugra          #+#    #+#             */
/*   Updated: 2023/08/31 15:26:17 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini.h"

void	ft_getenv(t_data *data, char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	data->env_len = i;
	data->env_cpy = ft_calloc(i + 1, sizeof(char *));
	i = 0;
	while (env[i])
	{
		data->env_cpy[i] = ft_strdup(env[i]);
		i++;
	}
}

void	ft_gethome(t_data *data)
{
	char	**split;
	int		i;

	i = -1;
	split = ft_split(data->pwd, '/');
	data->home = ft_strdup("/");
	while (split[++i] && i < 3)
	{
		data->home = ft_strjoinfree(data->home, split[i]);
		if (i < 2)
			data->home = ft_strjoinfree(data->home, "/");
	}
	ft_freesplit(split);
}

void	ft_getpath(t_data *data)
{
	int	i;

	i = 0;
	while (data->env_cpy[i])
	{
		if (!ft_strncmp("PATH=", data->env_cpy[i], 5))
		{
			data->path = ft_strdup(data->env_cpy[i] + 5);
			return ;
		}
		i++;
	}
	data->path = ft_calloc(1, 1);
}
