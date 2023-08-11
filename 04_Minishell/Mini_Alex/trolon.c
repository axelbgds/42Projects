/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trolon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:56:52 by jcasades          #+#    #+#             */
/*   Updated: 2023/07/05 11:13:35 by jcasades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_redirect(t_data *data, int i, int j)
{
	if (data->full[i][j] == '<' && j++)
	{
		if (data->full[i][j] == '<')
			j = ft_limit(data, i, j + 1, 0) + 1;
		else
		{
			j = ft_input(data, i, j, 0) + 1;
			if (j == 1)
				return (0);
		}
	}
	else if (data->full[i][j] == '>' && j++)
	{
		if (data->full[i][j] == '>')
			j = ft_openapp(data, i, j);
		else
			j = ft_opentrunk(data, i, j) + 1;
	}
	return (j);
}

static int	ft_sgl_quote(t_data *data, int i, int j)
{
	while (data->full[i][j] != '\'' && data->full[i][j] != '\0')
		data->new_cmd = ft_strjoinc
			(data->new_cmd, data->full[i][j++]);
	j++;
	return (j);
}

static int	ft_tp_quote(t_data *data, int i, int j)
{
	while (data->full[i][j] != '"' && data->full[i][j] != '\0')
	{
		if (data->full[i][j] == '$')
		{
			if (data->full[i][j + 1] != '?')
			{	
				data->arg = ft_reparg(data, i, j);
				data->new_cmd = ft_strjoinfree(data->new_cmd, data->arg);
				if (data->arg)
					free(data->arg);
			}
			else
				data->new_cmd = ft_strjoinfree(data->new_cmd,
						ft_itoa(data->errnum >> 8));
			while (data->full[i][j] != ' '
			&& data->full[i][j] != '"')
				j++;
		}
		data->new_cmd = ft_strjoinc(data->new_cmd, data->full[i][j]);
		j++;
	}
	return (j + 1);
}

static int	ft_tp_dollar(t_data *data, int i, int j)
{
	if (data->full[i][j + 1] != '?')
	{
		data->arg = ft_reparg(data, i, j);
		data->new_cmd = ft_strjoinfree(data->new_cmd, data->arg);
		if (data->arg)
			free(data->arg);
	}
	else
		data->new_cmd = ft_strjoinfree
			(data->new_cmd, ft_itoa(data->errnum >> 8));
	while (data->full[i][j] != ' '
			&& data->full[i][j] != '"' && data->full[i][j] != '\0')
		j++;
	return (j);
}

int	ft_third_parse(t_data *data, int i, int j)
{
	while (data->full[i][j])
	{
		if (data->full[i][j] == ' ' && j++)
		{
			data->new_cmd = ft_strjoinc(data->new_cmd, ' ');
			while (data->full[i][j] == ' ')
				j++;
		}
		else if ((data->full[i][j] == '>' || data->full[i][j] == '<') && j)
		{
			j = ft_redirect(data, i, j);
			if (j == 0)
				return (0);
		}
		else if (data->full[i][j] == '\'' && j++)
			j = ft_sgl_quote(data, i, j);
		else if (data->full[i][j] == '"' && j++)
			j = ft_tp_quote(data, i, j);
		else if (data->full[i][j] == '$')
			j = ft_tp_dollar(data, i, j);
		else
			data->new_cmd = ft_strjoinc(data->new_cmd, data->full[i][j++]);
	}
	ft_pludeplass(data, i);
	return (1);
}
