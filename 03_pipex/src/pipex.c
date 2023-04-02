

#include <pipex.h>

int	main(int argc, char **argv, char **envp)
{
	t_data	*d;

	if (argc != 5)
		return (1);
	d = malloc(sizeof(t_data));
	if (!d)
		return (1);
	d->argc = argc;
	d->argv = argv;
	d->envp = envp;
	ft_parse(d);
	ft_pipe(d);
	ft_cleanup(d);
	return (0);
}
