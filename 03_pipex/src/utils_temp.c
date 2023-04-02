
#include "pipex.h"

void	tmp_prt(t_data *d)
{
	int	i;
	int	j;

	ft_printf("printout args\n");
	i = 0;
	while (i < d->cnum)
	{
		j = 0;
		while (d->args && d->args[i] && d->args[i][j])
		{
			ft_putendl_fd(d->args[i][j], 2);
			j++;
		}
		i++;
	}
	ft_printf("printout paths\n");
	i = 0;
	while (i < d->cnum)
	{
		ft_putendl_fd(d->paths[i], 2);
		i++;
	}
}
