/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:30:03 by tde-los-          #+#    #+#             */
/*   Updated: 2023/07/05 12:48:05 by jcasades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_n(char *prompt, int i)
{
	while (prompt[i] == 'n')
		i++;
	while (prompt[i] == ' ')
		i++;
	if (!(prompt[i] == '-' && prompt[i + 1] == 'n'))
		return (i);
	else
		return (ft_check_n(prompt, i + 1));
}

int	ft_echo(t_data *data, char *prompt)
{
//	char		**split;
//	int			i;
//	int			flag;

	(void)data;
	if ((ft_strlen(prompt) > 7) && prompt[5] == '-' && prompt [6] == 'n')
		ft_printf("%s", prompt + ft_check_n(prompt, 7));
	else
		ft_printf("%s\n", prompt + 5);
//	split = ft_split(prompt, ' ');
//	if (!split[1])
//		return (ft_freesplit(split), ft_printf("\n"));
//	i = ft_check_n(split);
//	flag = i;
//	if (!split[i])
//		return (ft_freesplit(split), 0);
//	while (split[i])
//	{
//		if (split[i + 1])
//			ft_printf("%s ", split[i]);
//		else
//			ft_printf("%s", split[i]);
//		i++;
//	}
//	if (flag < 2)
//		ft_printf("\n");
//	return (ft_freesplit(split), 0);
	return (0);
}
