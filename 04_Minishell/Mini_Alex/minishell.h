/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:32:06 by ltressen          #+#    #+#             */
/*   Updated: 2023/07/05 11:06:45 by jcasades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define DQUOTE 1
# define SQUOTE 2
/*      Include     */
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
/*      Libft       */
# include "libft/libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include "libft/gnl/get_next_line.h"
/*      NAME        */
# define NAME "\033[1;36m☁️  Minichibre "
/*	STRUCTS	    */

typedef struct s_arg
{
	char	**argq;
	int		*flaq;
}	t_arg;

typedef struct s_data
{
	char	*pwd;
	char	**env_cpy;
	int		env_len;
	char	*home;
	char	**cmd;
	char	**full;
	char	*arg;
	char	*new_cmd;
	int		pipenum;
	int		**pipes;
	int		fd1;
	int		fd2;
	int		term;
	int		termo;
	int		*builtin;
	char	*oldstatus;
	int		old_pipe[2];
	int		new_pipe[2];
	int		errnum;
	char	*path;
	t_arg	args;
}	t_data;

char	*ft_readline(void);
char	*ft_readlines(char *temp, char *name, char *split);
void	ft_getpwd(t_data *data);
void	ft_getenv(t_data *data, char **env);
void	ft_cd(t_data *data, char *prompt);
void	ft_gethome(t_data *data);
int		ft_echo(t_data *data, char *prompt);
void	ft_exit(t_data *data, char *prompt);
void	ft_freesplit(char **split);
void	ft_export(t_data *data, char *prompt);
void	ft_new_export(t_data *data, char *c);
int		ft_unset(t_data *data, char *prompt);
int		ft_lenvar(char *varName);
void	ft_ctrl_c(int signal);
void	ft_parsingg(t_data *data, char *prompt);
void	delete_tmpfile(char *file, t_data *data);
char	*ft_chk_cmd(t_data *data, int i, int j);
char	*ft_reparg(t_data *data, int i, int j);
char	*ft_strjoinc(char *s1, char s2);
char	**ft_neosplit(char *str, char c, int i, int j);
int		ft_opentrunk(t_data *data, int i, int j);
int		ft_openapp(t_data *data, int i, int j);
int		ft_input(t_data *data, int i, int j, int l);
int		ft_limit(t_data *data, int i, int j, int l);
char	*ft_get_arg(t_data *data, int j, char *res);
void	ft_second_parse(t_data *data);
int		ft_first_parse(t_data *data, char *prompt);
void	is_builtin(t_data *data, char *cmd, int i);
void	ft_exec(t_data *data, int i, int flag);
int		ft_third_parse(t_data *data, int i, int j);
void	ft_execve(t_data *data, int i);
void	ft_error(t_data *data, char *error);
void	ft_init(t_data *data, char **env);
int		check_quote(char *str);
int		ft_no_built(char *str);
void	ft_getpath(t_data *data);
char	*ft_strjoinfree(char *s1, char *s2);
void	ft_go_pipe(t_data *data, int i);
void	single_cmd(t_data *data);
void	ft_pludeplass(t_data *data, int i);

#endif
