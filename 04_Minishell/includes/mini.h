/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 10:03:27 by alsaez            #+#    #+#             */
/*   Updated: 2023/08/31 15:10:53 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

# define DQUOTE 1
# define SQUOTE 2

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/signal.h>
# include <errno.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "../includes/libft.h"

# define NAME "\033[1;36m☁️  Minichibron "

typedef struct s_data
{
	char	*pwd;
	char	**env_cpy;
	int		env_len;
	char	*home;
	char	*path;

	char	**cmd;
	char	**full;
	char	*arg;
	char	*new_cmd;

	int		pipenum;
	int		**pipes;
	int		term;
	int		termo;

	int		errnum;
}	t_data;

// readline
char	*ft_readline(void);
char	*ft_readlines(char *temp, char *name, char *split);
// builtins
void	ft_getpwd(t_data *data);
void	ft_getenv(t_data *data, char **env);
char	*ft_get_arg(t_data *data, int j, char *res);
void	ft_cd(t_data *data, char *prompt);
int		ft_echo(t_data *data, char *prompt);
void	ft_export(t_data *data, char *prompt);
int		ft_unset(t_data *data, char *prompt);
void	ft_exit(t_data *data, char *prompt);
void	ft_new_export(t_data *data, char *c);
void	ft_gethome(t_data *data);
void	ft_getpath(t_data *data);
// parsing
void	ft_parsingg(t_data *data, char *prompt);
char	*ft_strjoinc(char *s1, char s2);
void	is_builtin(t_data *data, char *cmd, int i);
char	*ft_getquote(t_data *data, int i, int j);
char	*ft_chk_cmd(t_data *data, int i, int j);
char	**ft_neosplit(char *str, char c, int i, int j);
int		ft_opentrunk(t_data *data, int i, int j);
int		ft_openapp(t_data *data, int i, int j);
int		ft_input(t_data *data, int i, int j, int l);
int		ft_limit(t_data *data, int i, int j, int l);
void	ft_second_parse(t_data *data);
// exit - neosplit
void	ft_exec(t_data *data, int i, int flag);
int		ft_third_parse(t_data *data, int i, int j);
void	ft_execve(t_data *data, int i);
void	ft_error(t_data *data, char *cmd, char *error);
void	ft_init(t_data *data, char **env);
int		check_quote(char *str);
int		ft_no_built(char *str);
void	ft_go_pipe(t_data *data, int i);
void	single_cmd(t_data *data);
// signaux
void	ft_ctrl_c(int signal);
// utils
int		ft_lenvar(char *varName);
int		ft_pludeplass(t_data *data, int i);
void	ft_freesplit(char **split);
char	*ft_strjoinfree(char *s1, char *s2);
int		is_str_alpha(char *str);
char	*ft_sjf(char *s1, char *s2);

#endif