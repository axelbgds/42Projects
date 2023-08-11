/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:38:43 by tde-los-          #+#    #+#             */
/*   Updated: 2023/06/30 10:21:19 by ltressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_getpwd(t_data *data)
{
	char	*buff;

	if (data->pwd)
		free(data->pwd);
	buff = ft_calloc(4096 + 1, sizeof(char));
	getcwd(buff, 4096);
	data->pwd = ft_strdup(buff);
	free(buff);
}
