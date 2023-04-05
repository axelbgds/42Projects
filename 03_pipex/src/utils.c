/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perp.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:54:03 by abeaugra          #+#    #+#             */
/*   Updated: 2023/04/05 12:10:06 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* close_pipe_fds : close all pipes read ad write file descriptors */
static void close_pipe_fds(t_data *data)
{
    int i;

    i = 0;
    while (i < (data->nb_cmds - 1) * 2)
    {
        close(data->pipe[i]);
        i++;
    }
}

/* exit error : in case of error, print and error message and closes any open fd */
void    exit_error(int error_status, t_data *data)
{
    if (data)
    {
        close_fds(data);
        if (data->pipe != NULL)
            free(data->pipe);
        if (data->pids != NULL)
            free(data->pids);
        if (data->cmd_options != NULL || data->cmd_path != NULL)
            free_strs(data->cmd_path, data->cmd_options);
    }
    if (data->heredoc == 1)
        unlink(".heredoc.tmp");
    exit(error_status);
}

/* error_msg to the standard error fd return the error code*/
int     msg(char *str1, char *str2, char *str3, int erno)
{
    ft_putstr_fd("pipex: ", 2);
    ft_putstr_fd(str1, 2);
    ft_putstr_fd(str2, 2);
    ft_putstr_fd(str3, 2);
    return (erno);
}

/* clode fds used to close any open fd in case of error */
void    close_fds(t_data *data)
{
    if (data->fd_in != -1)
        close(data->fd_in);
    if (data->fd_out != -1)
        close(data->fd_out);
    close_pipe_fds(data);
}

/* free _strs : free a string and or array or strings if they are not already NULL*/
void    free_strs(char *str, char **strs)
{
    int i;

    if (str != NULL)
    {
        free(str);
        str = NULL;
    }
    if (strs != NULL)
    {
        i = 0;
        while (strs[i])
        {
            free(strs[i]);
            i++;
        }
        free(strs);
        strs = NULL;
    }
} 