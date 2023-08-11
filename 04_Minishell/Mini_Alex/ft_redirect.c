/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:18:59 by jcasades          #+#    #+#             */
/*   Updated: 2023/07/03 14:23:02 by jcasades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_opentrunk(t_data *data, int i, int j)
{
	int		k;
	int		l;
	char	*cmd;
	int		fd;

	j++;
	l = 0;
	while (data->full[i][j] == ' ' && data->full[i][j])
		j++;
	k = j;
	while (data->full[i][j] != ' ' && data->full[i][j])
		j++;
	cmd = malloc(j - k + 1);
	while (data->full[i][k] != ' ' && data->full[i][k])
	{
		cmd[l] = data->full[i][k];
		l++;
		k++;
	}
	cmd[l] = '\0';
	fd = open(cmd, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	dup2(fd, 1);
	close(fd);
	free(cmd);
	return (j);
}

int	ft_openapp(t_data *data, int i, int j)
{
	int		k;
	int		l;
	char	*cmd;
	int		fd;

	j += 2;
	l = 0;
	while (data->full[i][j] == ' ' && data->full[i][j])
		j++;
	k = j;
	while (data->full[i][j] != ' ' && data->full[i][j])
		j++;
	cmd = malloc(j - k + 1);
	while (data->full[i][k] != ' ' && data->full[i][k])
	{
		cmd[l] = data->full[i][k];
		l++;
		k++;
	}
	cmd[l] = '\0';
	fd = open(cmd, O_CREAT | O_APPEND | O_WRONLY, 0644);
	dup2(fd, 1);
	close(fd);
	free(cmd);
	return (j);
}

int	ft_limit(t_data *data, int i, int j, int l)
{
	int		k;
	char	*cmd;
	char	*new_prompt;

	while (data->full[i][j] == ' ' && data->full[i][j])
		j++;
	k = j;
	while (data->full[i][j] != ' ' && data->full[i][j])
		j++;
	cmd = malloc(j - k + 1);
	while (data->full[i][k] != ' ' && data->full[i][k])
		cmd[l++] = data->full[i][k++];
	cmd[l] = '\0';
	if (!cmd[0])
	{
		ft_error(data, "empty delimiter\n");
		return (j);
	}
	while (1)
	{
		new_prompt = readline(">");
		if (!ft_strncmp(new_prompt, cmd, ft_strlen(cmd)))
			break ;
	}
	return (j);
}

int	ft_input(t_data *data, int i, int j, int l)
{
	int		k;
	char	*cmd;
	int		fd;

	while (data->full[i][j] == ' ' && data->full[i][j])
		j++;
	k = j;
	while (data->full[i][j] != ' ' && data->full[i][j])
		j++;
	cmd = malloc(j - k + 1);
	while (data->full[i][k] != ' ' && data->full[i][k])
		cmd[l++] = data->full[i][k++];
	cmd[l] = '\0';
	fd = open(cmd, O_RDONLY);
	if (fd < 0)
	{
		ft_error(data, "error cpt mdr\n");
		return (0);
	}
	dup2(fd, 0);
	close(fd);
	return (j);
}

void	ft_error(t_data *data, char *error)
{
	dup2(data->term, 1);
	close(data->term);
	ft_printf("%s", error);
}
