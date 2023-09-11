/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:38:43 by alsaez            #+#    #+#             */
/*   Updated: 2023/08/31 15:26:56 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini.h"

int	ft_no_built(char *str)
{
	if (((!ft_strncmp(str, "cd", 3)
				|| !ft_strncmp(str, "echo", 5)
				|| !ft_strncmp(str, "export", 7)
				|| !ft_strncmp(str, "unset", 6)
				|| !ft_strncmp(str, "env", 4)
				|| !ft_strncmp(str, "pwd", 4))))
		return (1);
	return (0);
}

void	ft_second_parse(t_data *data)
{
	int	i;

	i = 0;
	data->pipes = ft_calloc(data->pipenum, sizeof(int *));
	while (i < data->pipenum - 1)
	{
		data->pipes[i] = malloc(sizeof(int) * 2);
		pipe(data->pipes[i]);
		i++;
	}
}

static int	ft_fp_suite(t_data *data, int i)
{
	char	**tmp;

	tmp = ft_split(data->full[i], ' ');
	if (tmp[0])
		data->cmd[i] = ft_strdup(tmp[0]);
	else
	{
		ft_freesplit(data->full);
		ft_freesplit(data->cmd);
		ft_freesplit(tmp);
		return (0);
	}
	ft_freesplit(tmp);
	return (1);
}

int	ft_first_parse(t_data *data, char *prompt)
{
	int		i;

	i = 0;
	if (prompt[0])
	{
		if (check_quote(prompt) == 1)
			data->full = ft_neosplit(prompt, '|', 0, 0);
		else
		{
			ft_error(data, prompt, "Erreur : Guillemets.\n");
			return (0);
		}
	}
	if (prompt[0] == '\0')
		return (0);
	while (data->full[i])
		i++;
	data->pipenum = i;
	data->cmd = ft_calloc((i + 1), sizeof(char *));
	i = 0;
	while (data->full[i])
		if (!ft_fp_suite(data, i++))
			return (0);
	return (i);
}

void	ft_parsingg(t_data *data, char *prompt)
{
	if (!ft_first_parse(data, prompt))
		return ;
	if (data->pipenum > 1)
		ft_second_parse(data);
	if (data->pipenum == 1 && !ft_strncmp(data->cmd[0], "exit", 5))
		ft_exit(data, prompt);
	else if (data->pipenum == 1 && (ft_no_built(data->cmd[0])))
		ft_exec(data, 0, 0);
	else if (data->pipenum == 1)
		single_cmd(data);
	else
		ft_go_pipe(data, 0);
	dup2(data->term, 1);
	dup2(data->termo, 0);
	ft_freesplit(data->full);
	ft_freesplit(data->cmd);
}
