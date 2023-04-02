

#include <pipex.h>

/* test path/cmd possible combinations for executability */
void	ft_pathexist(char **envpaths, char **path, char *cmd)
{
	char	*tmp;
	char	*tmp1;
	int		i;

	i = 0;
	while (envpaths && envpaths[i])
	{
		tmp = ft_strjoin(envpaths[i], "/");
		tmp1 = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!access(tmp1, X_OK))
		{
			*path = tmp1;
			return ;
		}
		free(tmp1);
		i++;
	}
}

/* char ** of PATHs */
void	ft_envpaths(t_data *d)
{
	int		i;

	d->envpaths = NULL;
	i = 0;
	while (d->envp && d->envp[i])
	{
		if (!ft_strncmp(d->envp[i], "PATH", 4))
			d->envpaths = ft_split(d->envp[i] + 5, ':');
		i++;
	}
}

/* char ** of command paths (1st arg for execve)*/
void	ft_paths(t_data *d)
{
	int		i;
	char	**cmds;

	d->paths = ft_calloc(d->cnum, sizeof(char *));
	if (!d->paths)
		ft_cleanup(d);
	ft_envpaths(d);
	i = 0;
	while (i < d->cnum)
	{
		if (ft_strchr(d->argv[i + 2], '/') && !ft_prevsp(d->argv[i + 2]))
			d->paths[i] = ft_strdup(d->argv[i + 2]);
		else
		{
			cmds = ft_split(d->argv[i + 2], ' ');
			ft_pathexist(d->envpaths, &d->paths[i], cmds [0]);
			ft_freesplit(cmds);
		}
		i++;
	}
}

/* build 2nd argument for execve */
void	ft_args(t_data *d)
{
	d->args = ft_calloc(d->cnum, sizeof(char *));
	if (!d->args)
		ft_cleanup(d);
	ft_mgexcept(d);
}

/* return t_data values parsing arguments of main */
void	ft_parse(t_data *d)
{
	d->cnum = d->argc - 3;
	ft_paths(d);
	ft_args(d);
	d->files[0] = d->argv[1];
	d->files[1] = d->argv[d->argc - 1];
}
