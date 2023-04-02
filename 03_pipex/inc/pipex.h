
#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <libft.h>
# include <sys/errno.h>
# include <string.h>

typedef struct s_data
{
	int		argc;
	char	**argv;
	char	**envp;
	char	**paths;
	char	***args;
	char	**envpaths;
	char	*files[2];
	int		fd[2];
	int		id;
	int		infiled;
	int		outfiled;
	int		cnum;
	int		ci;
	int		wstatus;
	int		flag;
}			t_data;

void	ft_cleanup(t_data *d);
void	ft_parse(t_data *d);
void	ft_pipe(t_data *d);
char	**ft_cond_split(char *str);
int		ft_chkquotes(char *str);
int		ft_chkqmesc(char *str);
char	*ft_nest(char *str);
int		ft_prevsp(char *str);
char	*ft_remdblesc(char *str);
void	ft_mgexcept(t_data *d);
void	tmp_prt(t_data *d);

#endif
