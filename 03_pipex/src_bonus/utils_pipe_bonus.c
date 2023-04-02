

#include <pipex_bonus.h>

/* wait children processes, feedback exitstatus */
void	ft_wait(t_data *d)
{
	while (1)
	{
		if (waitpid(-1, &d->wstatus, 0) == -1)
			break ;
		d->flag = WEXITSTATUS(d->wstatus);
	}
}

/* infile to STDIN, if existing and accessible */
void	ft_firstcmd(t_data *d)
{
	if (d->ci == 0)
	{
		d->infiled = open(d->files[0], O_RDONLY, 0644);
		if (d->infiled < 0)
		{
			perror(d->files[0]);
			d->flag = errno;
			ft_cleanup(d);
		}
		dup2(d->infiled, STDIN_FILENO);
		close(d->infiled);
	}
}

/* STDOUT to pipe, or to outfile if last cmd */
void	ft_pipein(t_data *d)
{
	int	r;

	if (d->ci != d->cnum - 1)
		dup2(d->fd[1], STDOUT_FILENO);
	else
	{
		if (d->hd_offset)
			r = O_WRONLY | O_CREAT | O_APPEND;
		else
			r = O_WRONLY | O_CREAT | O_TRUNC;
		d->outfiled = open(d->files[1], r, 0644);
		if (d->outfiled == -1)
		{
			perror(d->files[1]);
			d->flag = errno;
			ft_cleanup(d);
		}
		dup2(d->outfiled, STDOUT_FILENO);
		close(d->outfiled);
	}
}

/* child processes execve*/
void	ft_child(t_data	*d)
{
	int		err;

	close(d->fd[0]);
	ft_pipein(d);
	ft_firstcmd(d);
	if (!d->paths[d->ci])
	{
		ft_putstr_fd("command not found : ", STDERR_FILENO);
		ft_putstr_fd(d->args[d->ci][0], STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		if (d->ci == 0)
			d->flag = 1;
		else
			d->flag = 127;
		ft_cleanup(d);
	}
	err = execve(d->paths[d->ci], d->args[d->ci], d->envp);
	if (err == -1)
	{
		perror(d->args[d->ci][0]);
		d->flag = errno;
		ft_cleanup(d);
	}
}

/* pipe, fork, STDIN to pipe (parent process)*/
void	ft_pipe(t_data *d)
{
	d->ci = 0;
	while (d->ci < d->cnum)
	{
		if (pipe(d->fd) == -1)
			ft_cleanup(d);
		d->id = fork();
		if (d->id == -1)
			ft_cleanup(d);
		if (d->id == 0)
			ft_child(d);
		else
		{
			close(d->fd[1]);
			dup2(d->fd[0], STDIN_FILENO);
			close(d->fd[0]);
		}
		d->ci++;
	}
	ft_wait(d);
}
