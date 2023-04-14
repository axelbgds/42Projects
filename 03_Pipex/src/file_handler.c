/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perp.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:53:57 by abeaugra          #+#    #+#             */
/*   Updated: 2023/04/07 13:38:50 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* Dans l'ensemble, ce code gère les fichiers d'entrée et de sortie en fonction 
** de la configuration de "pipex" et de la présence de "heredoc"
** Configure le descripteur de fichier d'entrée pour "pipex". Si "heredoc" est 
** spécifié, un fichier temporaire est créé, sinon le fichier d'entrée spécifié
sera ouvert. */
void	get_input_file(t_data *d)
{
	if (d->heredoc == 1)
	{
		get_heredoc(d);
		d->fd_in = open(".heredoc.tmp", O_RDONLY);
		if (d->fd_in == -1)
			exit_error(msg("here_doc", ": ", strerror(errno), 1), d);
	}
	else
	{
		d->fd_in = open(d->av[1], O_RDONLY, 644);
		if (d->fd_in == -1)
			msg(strerror(errno), ": ", d->av[1], 1);
	}
}

/* Ouvre/crée un fichier de sortie. Si "heredoc" est spécifié, le fichier de 
** sortie sera en mode  "append", sinon il sera écrasé.*/
void	get_output_file(t_data *d)
{
	if (d->heredoc == 1)
		d->fd_out = open(d->av[d->ac -1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		d->fd_out = open(d->av[d->ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (d->fd_out == -1)
		msg(strerror(errno), ": ", d->av[d->ac -1], 1);
}

/* Crée un fichier temporaire pour stocker les données "heredoc" saisies 
** par l'utilisateur. Les données sont lues ligne par ligne à partir 
** de l'entrée standard et écrites dans le fichier temporaire jusqu'à ce 
** que la ligne de délimitation soit rencontrée. */
void	write_heredoc_to_tmp_file(int tmp_fd, int stdin_fd,
		const char *delimiter)
{
	char	*line;

	while (1)
	{
		ft_putstr_fd("here_doc >", 1);
		line = get_next_line(stdin_fd);
		if (line == NULL)
			break ;
		if (ft_strlen(delimiter) + 1 == ft_strlen(line)
			&& !ft_strncmp(line, delimiter, ft_strlen(delimiter + 1)))
		{
			close(stdin_fd);
			break ;
		}
		else
		{
			ft_putstr_fd(line, tmp_fd);
			free(line);
		}
	}
}

void	get_heredoc(t_data *d)
{
	int			tmp_fd;
	int			stdin_fd;
	const char	*delimiter;

	delimiter = d->av[2];
	tmp_fd = open(".heredoc.tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	stdin_fd = dup(STDIN_FILENO);
	if (tmp_fd == -1)
		exit_error(msg("here_doc", ": ", strerror(errno), 1), d);
	write_heredoc_to_tmp_file(tmp_fd, stdin_fd, delimiter);
	close(tmp_fd);
}

/* Crée un fichier temporaire pour stocker les données "heredoc" saisies 
** par l'utilisateur. Les données sont lues ligne par ligne à partir 
** de l'entrée standard et écrites dans le fichier temporaire jusqu'à ce 
** que la ligne de délimitation soit rencontrée. */
/*void	get_heredoc(t_data *d)
{
	int		tmp_fd;
	int		stdin_fd;
	char	*line;

	tmp_fd = open(".heredoc.tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	stdin_fd = dup(STDIN_FILENO);
	if (tmp_fd == -1)
		exit_error(msg("here_doc", ": ", strerror(errno), 1), d);
	line = "";
	while (1)
	{
		ft_putstr_fd("here_doc >", 1);
		line = get_next_line(stdin_fd);
		if (line == NULL)
			break ;
		if (ft_strlen(d->av[2]) + 1 == ft_strlen(line)
			&& !ft_strncmp(line, d->av[2], ft_strlen(d->av[2] +1)))
		{
			close(stdin_fd);
			break ;
		}
		else
		{
			ft_putstr_fd(line, tmp_fd);
			free(line);
		}
	}
	close(tmp_fd);
}*/
