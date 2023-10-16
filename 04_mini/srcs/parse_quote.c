/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:56:52 by alsaez            #+#    #+#             */
/*   Updated: 2023/09/04 16:35:19 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini.h"

static int	ft_redirect(t_data *data, int i, int j)
{
	if (data->full[i][j] == '<')
	{
		if (data->full[i][j + 1] == '<')
			j = ft_limit(data, i, j + 2, 0) + 1;
		else
		{
			j = ft_input(data, i, j + 1, 0) + 1;
			if (j == 1)
				return (0);
		}
	}
	else if (data->full[i][j] == '>')
	{
		if (data->full[i][j + 1] == '>')
			j = ft_openapp(data, i, j + 1);
		else
			j = ft_opentrunk(data, i, j + 1) + 1;
	}
	return (j);
}

static int	ft_sgl_quote(t_data *data, int i, int j)
{
	if (!ft_strncmp(data->cmd[i], "echo", 5))
		data->new_cmd = ft_strjoinc(data->new_cmd, '\a');
	while (data->full[i][j] != '\'' && data->full[i][j] != '\0')
		data->new_cmd = ft_strjoinc
			(data->new_cmd, data->full[i][j++]);
	j++;
	if (!ft_strncmp(data->cmd[i], "echo", 5))
		data->new_cmd = ft_strjoinc(data->new_cmd, '\a');
	return (j);
}

static int	ft_tp_quote(t_data *data, int i, int j)
{
	if (!ft_strncmp(data->cmd[i], "echo", 5))
		data->new_cmd = ft_strjoinc(data->new_cmd, '\a');
	while (data->full[i][j] != '"' && data->full[i][j] != '\0')
	{
		if (data->full[i][j] == '$')
		{
			if (data->full[i][j + 1] != '?')
			{
				data->arg = ft_getquote(data, i, j);
				data->new_cmd = ft_strjoinfree(data->new_cmd, data->arg);
				if (data->arg)
					free(data->arg);
			}
			else
				data->new_cmd = ft_sjf(data->new_cmd, ft_itoa(data->errnum));
			while (data->full[i][j] != ' '
			&& data->full[i][j] != '"' && data->full[i][j] != '\'')
				j++;
		}
		if (data->full[i][j] != '"')
			data->new_cmd = ft_strjoinc(data->new_cmd, data->full[i][j++]);
	}
	if (!ft_strncmp(data->cmd[i], "echo", 5))
		data->new_cmd = ft_strjoinc(data->new_cmd, '\a');
	return (j + 1);
}

static int	ft_tp_dollar(t_data *data, int i, int j)
{
	if (data->full[i][j + 1] != '?')
	{
		data->arg = ft_getquote(data, i, j);
		data->new_cmd = ft_strjoinfree(data->new_cmd, data->arg);
		if (data->arg)
			free(data->arg);
		while (data->full[i][j] != ' '
			&& data->full[i][j] != '"' && data->full[i][j] != '\0')
			j++;
		return (j);
	}
	else
		data->new_cmd = ft_sjf
			(data->new_cmd, ft_itoa(data->errnum >> 8));
	return (j + 2);
}

int	ft_third_parse(t_data *data, int i, int j)
{
	while (data->full[i][j])
	{
		if (data->full[i][j] == ' ' && j++)
		{
			while (data->full[i][j] == ' ')
				j++;
			if (data->full[i][j])
				data->new_cmd = ft_strjoinc(data->new_cmd, ' ');
		}
		else if (data->full[i][j] == '\'' && j++)
			j = ft_sgl_quote(data, i, j);
		else if (data->full[i][j] == '"' && j++)
			j = ft_tp_quote(data, i, j);
		else if (data->full[i][j] == '$')
			j = ft_tp_dollar(data, i, j);
		else if ((data->full[i][j] == '>' || data->full[i][j] == '<'))
		{
			j = ft_redirect(data, i, j);
			if (j == 0)
				return (free(data->new_cmd), 0);
		}
		else
			data->new_cmd = ft_strjoinc(data->new_cmd, data->full[i][j++]);
	}
	return (ft_pludeplass(data, i));
}
