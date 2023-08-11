/* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:16:24 by jcasades          #+#    #+#             */
/*   Updated: 2023/06/19 11:15:26 by ltressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_execve(t_data *data, int i)
{
	char	*cmd;
	pid_t	pid;
	int	status;

		cmd = ft_chk_cmd(data, i);
		if (cmd)
		{
			if (execve(cmd, ft_split(data->cmd_full[i], ' '), data->env_cpy) == -1)
				exit(1);
			exit(1);		//ft_printf("%d, %s\n", errno, strerror(errno));
		}
		else
			exit(1) ;
}

void	ft_exec(t_data *data, int i, int flag)
{
	int	j;

	j = 0;
	if (!data->cmd[0])
		exit(1) ;
	if (!ft_strncmp(data->cmd[i], "cd", 3))
		ft_cd(data, data->cmd_full[i]);
	else if (!ft_strncmp(data->cmd[i], "echo", 5))
		ft_echo(data, data->cmd_full[i]);
	else if (!ft_strncmp(data->cmd[i], "export", 7))
		ft_export(data, data->cmd_full[i]);
	else if (!ft_strncmp(data->cmd[i], "unset", 6))
		ft_unset(data, data->cmd_full[i]);
	else if (!ft_strncmp(data->cmd[i], "env", 4))
		while (data->env_cpy[j])
			ft_printf("%s\n", data->env_cpy[j++]);
	else if (!ft_strncmp(data->cmd[i], "pwd", 4))
	{
		ft_getpwd(data);
		ft_printf("%s\n", data->pwd);
	}		
	else if (!ft_strncmp(data->cmd[i], "exit", 5))
		ft_exit(data, NULL);
	else
	{
		ft_execve(data, i);
		//exit(1);
	}
	if ((!ft_strncmp(data->cmd[i], "cd", 3) || !ft_strncmp(data->cmd[i], "echo", 5) || !ft_strncmp(data->cmd[i], "export", 7) || !ft_strncmp(data->cmd[i], "unset", 6) || !ft_strncmp(data->cmd[i], "env", 4) || !ft_strncmp(data->cmd[i], "pwd", 4)) && flag == 1)
		exit(1);

}

void	is_builtin(t_data *data, char *cmd, int i)
{
	if (!ft_strncmp(cmd, "cd", 3))
		data->builtin[i] = 1;
	else if (!ft_strncmp(cmd, "echo", 5))
		data->builtin[i] = 1;
	else if (!ft_strncmp(cmd, "export", 7))
		data->builtin[i] = 1;
	else if (!ft_strncmp(cmd, "unset", 6))
		data->builtin[i] = 1;
	else if (!ft_strncmp(cmd, "env", 4))
		data->builtin[i] = 1;
	else if (!ft_strncmp(cmd, "pwd", 4))
		data->builtin[i] = 1;
	else if (!ft_strncmp(cmd, "exit", 5))
		data->builtin[i] = 1;
	else
		data->builtin[i] = 0;
}

int	ft_first_parse(t_data *data, char *prompt)
{
	int	i;
	int	j;
	char	**tmp;

	i = 0;
	data->cmd_full=ft_split(prompt, '|');
	while (data->cmd_full[i])
		i++;
	data->pipenum = i;
	data->cmd = ft_calloc((i + 1), sizeof(char *));
	i = 0;
	while (data->cmd_full[i])
	{
		tmp = ft_split(data->cmd_full[i], ' ');
		if (tmp[0])
			data->cmd[i] = ft_strdup(tmp[0]);
		else
		{
			ft_freesplit(data->cmd_full);
			ft_freesplit(data->cmd);
			ft_freesplit(tmp);
			return (i);
		}
		ft_freesplit(tmp);
		i++;
	}
	
	// data->builtin = malloc((i + 1) * 4);
	// i = 0;
	// while (data->cmd[i])
	// {
	// 	is_builtin(data, data->cmd[i], i);
	// 	i++;
	// }
	//free(data->builtin);
	return (i);
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

char	*ft_chk_cmd(t_data *data, int i)
{
	char	**pbl;
	char	**spt;
	int	j;
	char	*new_cmd;

	j = 0;
	while (ft_strncmp("PATH", data->env_cpy[j], 4))
		j++;
	pbl = ft_split(data->env_cpy[j], '=');
	spt = ft_split(pbl[1], ':');
	j = 0;
	while (spt[j])
	{
		new_cmd = ft_strjoin(spt[j], "/");
		if (access(ft_strjoin(new_cmd, data->cmd[i]), 0) == 0)
		{
			ft_freesplit(pbl);
			ft_freesplit(spt);
			return (ft_strjoin(new_cmd, data->cmd[i]));
		}
		free(new_cmd);
		j++;
	}
	ft_freesplit(pbl);
	ft_freesplit(spt);
	return (NULL);
}
void	close_pipes(t_data *data)
{
	int	i;

	i = 0;
	while (data->pipes[i])
	{
		close(data->pipes[i][0]);
		close(data->pipes[i][1]);
		i++;
	}
}
pid_t	ft_piping(t_data *data, int i)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (i == 0)
		{
			dup2(data->pipes[i][1], 1);	
		}
		else if (i == data->pipenum - 1) 
		{
			dup2(data->pipes[i - 1][0], 0);
		}
		else
		{
			dup2(data->pipes[i- 1][0], 0);
			dup2(data->pipes[i][1], 1);
		}
		close_pipes(data);
		ft_exec(data, i, 1);
	}
	return (pid);
}


void	single_cmd(t_data *data)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
		ft_exec(data, 0, 1);
	waitpid(-1, NULL, 0);
}

void	ft_parsingg(t_data *data, char *prompt)
{
	int	i;
	int pid;
	
	i = 0;
	if (!ft_first_parse(data, prompt))
		return ;
	if (data->pipenum > 1)
		ft_second_parse(data);
	if (data->pipenum == 1 && !ft_strncmp(data->cmd[0], "exit", 5))
		ft_exit(data, prompt);
	else if (data->pipenum == 1 && ((!ft_strncmp(data->cmd[i], "cd", 3) || !ft_strncmp(data->cmd[i], "echo", 5) || !ft_strncmp(data->cmd[i], "export", 7) || !ft_strncmp(data->cmd[i], "unset", 6) || !ft_strncmp(data->cmd[i], "env", 4) || !ft_strncmp(data->cmd[i], "pwd", 4))))
		ft_exec(data, i, 0);
	else if (data->pipenum == 1)
		single_cmd(data);
	else
	{
		while (data->cmd_full[i])
		{
			pid = ft_piping(data, i);
			i++;
		}
		close_pipes(data);
		i = 0;
		while (i < data->pipenum)
		{
			waitpid(-1, NULL, 0);
			i++;
		}
	}
	
	ft_freesplit(data->cmd_full);
	ft_freesplit(data->cmd);
}


