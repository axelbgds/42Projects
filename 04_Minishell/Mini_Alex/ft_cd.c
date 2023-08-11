/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:06:22 by ltressen          #+#    #+#             */
/*   Updated: 2023/06/30 10:25:30 by ltressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// todo lorsqu'il y'a plus la valeur PWD / OLDPWD les rajouter a la fin de ENV

void	ft_check_pwd(t_data *data, char *str)
{
	char	**env_cpy;
	int		i;

	i = -1;
	while (data->env_cpy[++i])
		if (!ft_strncmp(data->env_cpy[i], str, ft_strlen(str)))
			return ;
	env_cpy = ft_calloc(data->env_len + 1, sizeof(char *));
	i = -1;
	while (data->env_cpy[++i])
		env_cpy[i] = data->env_cpy[i];
	env_cpy[i] = str;
	data->env_cpy = env_cpy;
}

void	ft_changepwd(t_data *data, char *old_pwd)
{
	char	*str;
	char	*str2;
	int		i;

	i = -1;
	ft_getpwd(data);
	str = ft_strjoin("PWD=", data->pwd);
	str2 = ft_strjoin("OLDPWD=", old_pwd);
	while (data->env_cpy[++i])
	{
		if (!ft_strncmp(data->env_cpy[i], "PWD", 3))
		{
			free(data->env_cpy[i]);
			data->env_cpy[i] = str;
		}
		if (!ft_strncmp(data->env_cpy[i], "OLDPWD", 6))
		{
			free(data->env_cpy[i]);
			data->env_cpy[i] = str2;
		}
	}
	ft_check_pwd(data, str);
	ft_check_pwd(data, str2);
}

void	ft_dollar_cd(t_data *data, char *arg)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (arg[i] == '$')
		i++;
	if (i != 1)
		ft_printf("cd: no such file or directory: %s\n", arg);
	arg++;
	arg = ft_strjoin(arg, "=");
	while (data->env_cpy[i])
	{
		if (!ft_strncmp(data->env_cpy[i], arg, ft_strlen(arg)))
		{
			while (data->env_cpy[i][j] != '=')
				j++;
			if (chdir(data->env_cpy[i] + j + 1) == -1)
				ft_printf("cd: no such file or directory: %s\n", \
					data->env_cpy[i] + j + 1);
			return ;
		}
		i++;
	}
	chdir(data->home);
}

void	ft_arg_cd(t_data *data, char *arg, char *pwd_copy)
{
	if (arg[0] == '~' && arg[1] == '~')
	{
		ft_printf("cd: no such file or directory: %s\n", arg);
		return ;
	}
	else if (arg[0] == '$')
		ft_dollar_cd(data, arg);
	else
	{
		chdir(data->home);
		if (chdir(arg + 2) == -1)
		{
			ft_printf("cd: no such file or directory: %s\n", arg);
			chdir(pwd_copy);
			return ;
		}
	}
}

void	ft_cd(t_data *data, char *prompt)
{
	char	**parse;
	char	*pwd_cpy;

	parse = ft_split(prompt, ' ');
	ft_getpwd(data);
	pwd_cpy = ft_strdup(data->pwd);
	if (!parse[1])
		chdir(data->home);
	else if (parse[1][0] != '$')
	{
		if (parse[1][0] == '~' && parse[1][1] == '\0')
			chdir(data->home);
		else if (parse[1][0] == '~' && parse[1][1] != '\0')
			ft_arg_cd(data, parse[1], pwd_cpy);
		else
			if (chdir(parse[1]) == -1)
				ft_printf("cd: no such file or directory: %s\n", parse[1]);
	}
	else
		ft_arg_cd(data, parse[1], pwd_cpy);
	ft_changepwd(data, pwd_cpy);
	free(pwd_cpy);
	ft_freesplit(parse);
}
