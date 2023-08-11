/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:31:30 by jcasades          #+#    #+#             */
/*   Updated: 2023/07/04 11:43:59 by ltressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_exit_free(t_data *data)
{
	free(data->home);
	free(data->path);
	ft_freesplit(data->env_cpy);
	ft_freesplit(data->cmd);
	ft_freesplit(data->full);
	free(data->pipes);
	free(data->pwd);
	free(data);
}

void	ft_exit(t_data *data, char *prompt)
{
	char	**sp;
	int		exit_code;

	exit_code = 0;
	if (prompt)
	{
		sp = ft_split(data->full[0], ' ');
		if (sp[1])
			exit_code = ft_atoi(sp[1]);
		free(prompt);
		ft_freesplit(sp);
	}
	else
	{
		free(data->home);
		free(data->pwd);
		free(data->path);
		ft_freesplit(data->env_cpy);
		free(data);
		exit(exit_code);
	}
	ft_exit_free(data);
	exit(exit_code);
}
